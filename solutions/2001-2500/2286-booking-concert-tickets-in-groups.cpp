typedef long long ll;

template<class T, class U>
// T -> node, U -> update.
struct Lsegtree {
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element; //combine(id, x) = x for all x
    U identity_update; //apply(id, x) = x for all x

    Lsegtree() {

    }

    Lsegtree(ll n, T identity_element, U identity_update) {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n, identity_element);
        lazy.assign(4*n, identity_update);
    }

    //change this function as required.
    //right now this is sum of two nodes.
    //we can change it to max(l, r), gcd(l, r), etc..
    T combine(T l, T r) {
        T ans;
        ans.first = l.first + r.first;
        ans.second = max(l.second, r.second);
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm + 1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    //change the following 2 functions, and you're more or less done.
    //apply the update to curr, which holds the range [tl, tr].
    //this is modification for all elements in the range.
    //if we wanted to add, we could change it to curr + (tr - tl + 1)*upd.
    T apply(T curr, U upd, ll tl, ll tr) {
        if (upd == this->identity_update) {
            return curr; //this means no update should be made
        }
        T ans;
        ans.first = (tr - tl + 1) * upd;
        ans.second = upd;
        return ans;
    }

    //there may be several updates already, so we need to combine them
    //this is modification, so we just replace the old value with new value
    //if we wanted addition, we could do ans = old_update + new_update
    U combineUpdate(U old_update, U new_update, ll tl, ll tr) {
        U ans = old_update;
        if (new_update != this->identity_update) {
            ans = new_update;
        }
        return ans;
    }

    void push_down(ll v, ll tl, ll tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            ll tm = (tl + tr) >> 1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v + 1], lazy[v], tl,tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v + 2], lazy[v],tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(ll v, ll tl, ll tr, ll l, ll r) {
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
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2*v + 1, tl, tm, l, r), queryUtil(2*v + 2,tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd) {
        push_down(v, tl, tr);
        if (tr < l || tl > r) return;
        if (tl >= l && tr <= r) {
            lazy[v] = combineUpdate(lazy[v],upd, tl, tr);
            push_down(v, tl, tr);
        }
        else {
            ll tm = (tl + tr) >> 1;
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
    T query(ll l, ll r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    //[l, r]
    void update(ll l,ll r, U upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};


class BookMyShow {
public:
    int start = 0;
    int n, m;
    Lsegtree<pair<ll, ll>, ll> st;
    void init() {
        st.n = n;
        st.identity_element = make_pair(0, 0);
        st.identity_update = -1;
        st.st.assign(4*n, st.identity_element);
        st.lazy.assign(4*n, st.identity_update);
        vector<pair<ll, ll>> a(n, make_pair(m, m));
        st.build(a);
    }

    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        start = 0;
        init();
    }

    void update_start_row() {
        while (start < n && st.query(start, start).second == 0) {
            start++;
        }
    }

    pair<int, int> find_row_with_k_spots(ll left, ll right, int k) {
        int index = -1, amount = -1;
        while (left <= right) {
            ll mid = left + (right - left)/2;
            ll cur_amount = st.query(start, mid).second;
            if (cur_amount >= k) {
                index = mid;
                amount = cur_amount;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return make_pair(index, amount);
    }

    vector<int> gather(int k, int maxRow) {
        if (start > maxRow) {
            return vector<int>{};
        }
        auto [row_index, amount] = find_row_with_k_spots(start, maxRow, k);
        if (row_index == -1) {
            return vector<int>{};
        }
        int rem = amount - k;
        int col_index = m - amount;
        vector<int> ans = {row_index, col_index};
        st.update(row_index, row_index, rem);
        update_start_row();
        return ans;
    }

    bool scatter(int k, int maxRow) {
        if (maxRow < start) {
            return false;
        }
        ll sum = st.query(start, maxRow).first;
        if (sum < k) {
            return false;
        }
        for (int row = start; row <= maxRow && k > 0; row++) {
            int cur_row_spots = st.query(row, row).first;
            if (cur_row_spots < k) {
                k -= cur_row_spots;
                st.update(row, row, 0);
            } else {
                cur_row_spots -= k;
                st.update(row, row, cur_row_spots);
                k = 0;
            }
        }
        update_start_row();
        return true;
    }
};
