typedef long long ll;

struct Node {
    ll sum;
    Node() : sum(0) {}
    Node(ll sum) : sum(sum) {}
    bool operator==(const Node& other) const {
        return sum == other.sum;
    }
    Node operator+(const Node& other) const {
        return Node(sum + other.sum);
    }
};

struct Update {
    ll x;
    Update() : x(0) {}
    Update(ll x) : x(x) {}
    bool operator==(const Update& other) const {
        return x == other.x;
    }
    Update operator+(const Update& other) const {
        return Update(x + other.x);
    }
};

struct LazySegmentTree {
    vector<Node> st;
    vector<Update> lazy;
    int n;
    Node identity_element; //combine(id, x) = x for all x
    Update identity_update; //apply(id, x) = x for all x

    LazySegmentTree(int n, Node identity_element, Update identity_update)
            : n(n), identity_element(identity_element), identity_update(identity_update) {
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }

    //combine the result of two nodes
    Node combine(Node l, Node r) {
        return Node(l.sum + r.sum);
    }

    //apply the update to curr, which holds the range [tl, tr].
    Node apply(Node curr, Update upd, int tl, int tr) {
        return Node(curr.sum + upd.x * (tr - tl + 1));
    }

    //there may be several updates already, so we need to combine them
    Update combineUpdate(Update old_update, Update new_update, int tl, int tr) {
        old_update.x += new_update.x;
        return old_update;
    }

    void push_down(int v, int tl, int tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            int tm = (tl + tr) >> 1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v + 1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    void buildUtil(int v, int tl, int tr, vector<Node> &a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        buildUtil(2*v + 1, tl, tm, a);
        buildUtil(2*v + 2, tm + 1, tr, a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    Node queryUtil(int v, int tl, int tr, int l, int r) {
        push_down(v, tl, tr);
        if (l > r) {
            return identity_element;
        }
        if (tr < l || tl > r) {
            return identity_element;
        }
        if (l <= tl && r >= tr) {
            return st[v];
        }
        int tm = (tl + tr) >> 1;
        return combine(queryUtil(2*v + 1, tl, tm, l, r), queryUtil(2*v + 2,tm + 1, tr, l, r));
    }

    void updateUtil(int v, int tl, int tr, int l, int r, Update upd) {
        push_down(v, tl, tr);
        if (tr < l || tl > r) return;
        if (tl >= l && tr <= r) {
            lazy[v] = combineUpdate(lazy[v],upd, tl, tr);
            push_down(v, tl, tr);
        }
        else {
            int tm = (tl + tr) >> 1;
            updateUtil(2*v+1, tl,tm, l, r, upd);
            updateUtil(2*v+2,tm+1 ,tr, l, r, upd);
            st[v] = combine(st[2*v + 1], st[2*v + 2]);
        }
    }

    void build(vector<Node>& a) {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }

    //[l, r]
    Node query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    //[l, r]
    void update(int l,int r, Update upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

class Solution {
public:
    long long solve(vector<int>& a) {
        int n = (int) a.size();
        long long ans = 0;
        map<int, vector<int>> mp;
        LazySegmentTree st(n, 0, 0);
        vector<Node> b(n);
        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i]);
            b[i] = Node(a[i]);
            mp[a[i]].push_back(i);
        }
        st.build(b);
        set<int> seen;
        for (auto &[key, locations]: mp) {
            set<pair<int, int>> subarrays;
            set<int> seen_now;
            for (auto &index: locations) {
                seen_now.insert(index);
                seen.insert(index);
                auto it = seen.lower_bound(index);
                int l = it == seen.begin() ? 0 : *prev(it);
                int r = next(it) == seen.end() ? n - 1 : *next(it);
                seen.erase(index);
                if (subarrays.find(make_pair(l, r)) != subarrays.end()) {
                    continue;
                }
                subarrays.insert(make_pair(l, r));
                int current_value = st.query(index, index).sum;
                ans += current_value;
                st.update(l, r, -1 * current_value);
            }
            for (auto &index: seen_now) {
                seen.insert(index);
            }
        }
        return ans;
    }

    int sign(int x) {
        if (x == 0) {
            return 0;
        }
        return x / abs(x);
    }
    
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = (int) nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++) {
            diffs[i] = target[i] - nums[i];
        }
        long long ans = 0;
        int prev_sign = sign(diffs[0]);
        vector<int> current_subarray = {diffs[0]};
        for (int i = 1; i < n; i++) {
            if (sign(diffs[i]) != prev_sign) {
                ans += solve(current_subarray);
                current_subarray.clear();
                prev_sign = sign(diffs[i]);
            }
            current_subarray.push_back(diffs[i]);
        }
        ans += solve(current_subarray);
        return ans;
    }
};
