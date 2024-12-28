class Solution {
public:
    int dp[101][101][101];
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        auto dfs = [&](auto &dfs, int i, int a, int b) -> int {
            if (i >= n) {
                return 0;
            }
            if (dp[i][a][b] != -1) {
                return dp[i][a][b];
            }
            int best = dfs(dfs, i + 1, a, b) + nums[i];
            if (a > 0) {
                best = min(best, dfs(dfs, i + 1, a - 1, b) + (nums[i] + 1) / 2);
            }
            if (b > 0 && nums[i] >= k) {
                 best = min(best, dfs(dfs, i + 1, a, b - 1) + nums[i] - k);
            }
            if (a > 0 && b > 0 && nums[i] >= k) {
                best = min(best, dfs(dfs, i + 1, a - 1, b - 1) + (nums[i] - k + 1) / 2);
                if ((nums[i] + 1) / 2 >= k) {
                    best = min(best, dfs(dfs, i + 1, a - 1, b - 1) + (nums[i] + 1) / 2 - k); 
                }
            }
            return dp[i][a][b] = best;
        };
        return dfs(dfs, 0, op1, op2);
    }
};
