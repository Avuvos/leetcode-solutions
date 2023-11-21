typedef long long ll;
const int N = 5e5 + 17;  // limit for array size
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
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        for (int i = 0; i < n; i++) {
            maximum[i + n] = heights[i];
        }
        build();
        int m = (int) queries.size();
        vector<int> ans(m, -1);
        for (int q = 0; q < m; q++) {
            int a = queries[q][0], b = queries[q][1];
            if (a == b) {
                ans[q] = a;
                continue;
            }
            if (a > b) {
                swap(a, b);
            }
            int left = b, right = n - 1, idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (max_query(left, mid + 1) > heights[a]) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans[q] = idx;
        }
        return ans;
    }
};
