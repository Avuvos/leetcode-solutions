class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        vector<int> ps(n + 1, 0);
        auto possible = [&](int k) -> bool {
            for (int i = 0; i <= n; i++) {
                ps[i] = 0;
            }
            for (int i = 0; i < k; i++) {
                int l = queries[i][0], r = queries[i][1], v = queries[i][2];
                ps[l] += v;
                ps[r + 1] -= v;
            }
            for (int i = 1; i <= n; i++) {
                ps[i] += ps[i - 1];
            }
            for (int i = 0; i < n; i++) {
                if (nums[i] - ps[i] > 0) {
                    return false;
                }
            }
            return true;
        };
        
        int left = 0, right = q, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
