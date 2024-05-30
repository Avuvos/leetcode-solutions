typedef long long ll;
const int N = 1e5 + 17;  // limit for array size
int n;  // array size
ll maximum[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) {
        maximum[i] = max(maximum[i << 1], maximum[i << 1 | 1]);
    }
}

void modify(int p, ll value) {  // set value at position p
    for (maximum[p += n] = value; p > 1; p >>= 1) {
        maximum[p >> 1] = max(maximum[p], maximum[p ^ 1]);
    }
}

ll max_query(int l, int r) {  // max on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res = max(res, maximum[l]);
            l++;
        }
        if (r & 1) {
            r--;
            res = max(res, maximum[r]);
        }
    }
    return res;
}


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> xs;
        int q = (int) queries.size();
        for (int i = 0; i < q; i++) {
            if (queries[i][0] == 1) {
                xs.push_back(queries[i][1]);
            }
        }
        
        xs.push_back(0);
        sort(xs.begin(), xs.end());
        map<int, int> x_to_idx;
        n = (int) xs.size();
        for (int i = 0; i < n; i++) {
            x_to_idx[xs[i]] = i;
            maximum[i + n] = 0;
        }
        build();
        
        set<int> positions;
        positions.insert(0);
        vector<bool> ans;
        for (int i = 0; i < q; i++) {
            int op = queries[i][0];
            if (op == 1) {
                int x = queries[i][1];
                auto it = positions.lower_bound(x);
                if (it != positions.end()) {
                    modify(x_to_idx[*it], *it - x);
                }
                modify(x_to_idx[x], x - *prev(it));
                positions.insert(x);
            } else if (op == 2) {
                int x = queries[i][1];
                int sz = queries[i][2];
                auto it = positions.lower_bound(x);
                bool ok = x - *prev(it) >= sz || max_query(0, x_to_idx[*prev(it)] + 1) >= sz;
                ans.push_back(ok);
            } else {
                assert(false);
            }
        }
        return ans;
    }
};
