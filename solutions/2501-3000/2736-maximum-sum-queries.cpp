class Solution {
public:
    typedef long long ll;
    int n;  // array size
    static const int N = 2 * 1e5 + 3;
    int maximum[2 * N];
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) {
            maximum[i] = max(maximum[i << 1], maximum[i << 1 | 1]);
        }
    }

    int max_query(int l, int r) {  // sum on interval [l, r)
        int res = -1;
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

    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        n = (int) nums1.size();
        vector<pair<int, int>> both(n);
        for (int i = 0; i < n; i++) {
            both[i].first = nums1[i];
            both[i].second = nums2[i];
        }
        sort(both.rbegin(), both.rend());

        vector<pair<int, int>> good;
        int max_y = 0;
        for (auto [x, y]: both) {
            if (y > max_y) {
                max_y = y;
                good.emplace_back(x, max_y);
            }
        }

        //both are sorted!
        n = (int) good.size();
        vector<int> updated_x(n), updated_y(n);
        for (int i = 0; i < good.size(); i++) {
            auto [x, y] = good[i];
            updated_x[i] = x;
            updated_y[i] = y;
            maximum[i + n] = x + y;
        }

        build();
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            int idx1 = int(lower_bound(updated_y.begin(), updated_y.end(), y) - updated_y.begin());
            int idx2 = -1;
            int l = 0, r = n - 1;
            while (l <= r) {
                int m = l + (r - l)/2;
                if (updated_x[m] >= x) {
                    idx2 = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (idx1 == n || idx2 == -1) continue;
            int left = idx1, right = idx2;
            ans[i] = (int) max_query(left, right + 1);
        }
        return ans;
    }
};
