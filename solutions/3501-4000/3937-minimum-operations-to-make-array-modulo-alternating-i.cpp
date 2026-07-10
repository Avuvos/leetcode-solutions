class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1e9 + 2;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;
                int cur = 0;
                for (int i = 0; i < n; i++) {
                    int r = nums[i] % k;
                    if (i % 2 == 0) {
                        cur += min({abs(x - r), x + k - r, k - x + r});
                    } else {
                        cur += min({abs(y - r), y + k - r, k - y + r});
                    }
                }
                ans = min(ans, cur);
            }
        }
        return ans;
    }
};
