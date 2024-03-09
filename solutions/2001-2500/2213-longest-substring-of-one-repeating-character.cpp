struct Node {
    int sum;
    int max_prefix;
    int max_suffix;
    int max_subarray;
    int len = 1;

    Node() {
        len = 1;
        sum = 0;
        max_prefix = 0;
        max_suffix = 0;
        max_subarray = 0;
    }

    Node(int sum, int max_prefix, int max_suffix, int max_subarray, int len) {
        this->sum = sum;
        this->max_prefix = max_prefix;
        this->max_suffix = max_suffix;
        this->max_subarray = max_subarray;
        this->len = len;
    }

    bool operator==(const Node& other) const {
        return sum == other.sum && max_prefix == other.max_prefix
        && max_suffix == other.max_suffix && max_subarray == other.max_subarray;
    }
};

template<class T, class U>
// T -> node, U -> update.
struct Lsegtree {
    vector<T> st;
    vector<U> lazy;
    int n;
    T identity_element; //combine(id, x) = x for all x
    U identity_update; //apply(id, x) = x for all x

    Lsegtree(int n, T identity_element, U identity_update) {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n, identity_element);
        lazy.assign(4*n, identity_update);
    }

    T combine(T l, T r) {
        T ans;
        ans.len = l.len + r.len;
        ans.sum = l.sum + r.sum;

        ans.max_prefix = l.max_prefix;
        if (l.sum == l.len) {
            ans.max_prefix += r.max_prefix;
        }
        ans.max_suffix = r.max_suffix;
        if (r.sum == r.len) {
            ans.max_suffix += l.max_suffix;
        }
        ans.max_subarray = max({l.max_subarray, r.max_subarray});
        ans.max_subarray = max({ans.max_subarray, ans.max_prefix, ans.max_suffix});
        ans.max_subarray = max({ans.max_subarray, l.max_suffix + r.max_prefix});

        return ans;
    }

    void buildUtil(int v, int tl, int tr, vector<T>&a) {
        if(tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    T apply(T curr, U upd, int tl, int tr) {
        if (upd == identity_update) {
            return curr;
        }
        T ans(upd, upd, upd, upd, 1);
        return ans;
    }

    U combineUpdate(U old_update, U new_update, int tl, int tr) {
        U ans = old_update;
        if (new_update != identity_update) {
            ans = new_update;
        }
        return ans;
    }

    void push_down(int v, int tl, int tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            int tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(int v, int tl, int tr, int l, int r) {
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
        int tm = (tl + tr)>>1;
        return combine(queryUtil(2*v + 1, tl, tm, l, r), queryUtil(2*v + 2,tm+1, tr, l, r));
    }

    void updateUtil(int v, int tl, int tr, int l, int r, U upd) {
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

    void build(vector<T>a) {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }

    //[l, r]
    T query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    //[l, r]
    void update(int l,int r, U upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = (int) s.size();
        Lsegtree<Node, int> id_seg(n, {0, 0, 0, 0, 1}, -1);
        vector<Lsegtree<Node, int>> segtree(26, id_seg);
        for (int i = 0; i < n; i++) {
            int j = s[i] - 'a';
            segtree[j].update(i, i, 1);
        }


        int k = (int) queryIndices.size();
        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            int prev = s[index] - 'a';
            segtree[prev].update(index, index, 0);

            s[index] = c;
            int current = c - 'a';
            segtree[current].update(index, index, 1);

            for (int j = 0; j < 26; j++) {
                ans[i] = max(ans[i], segtree[j].query(0, n - 1).max_subarray);
            }
        }
        return ans;
    }
};
