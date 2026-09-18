class Solution {
public:
    const int INF = 1e9 + 2;
    int dp[101][5001];
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        auto dfs = [&](auto &dfs, int i, int s) -> int {
            if (s == sum) {
                return 0;
            }
            if (i >= n || s > sum) {
                return INF;
            }
            if (dp[i][s] != -1) {
                return dp[i][s];
            }
            int x = nums[i], ops = 0;
            int best = min(dfs(dfs, i + 1, s), dfs(dfs, i + 1, s + x));
            while (x > 1) {
                ops++;
                x >>= 1;
                best = min(best, ops + dfs(dfs, i + 1, s + x));
            }
            x = nums[i], ops = 0;
            while (s + (x << 1) <= sum) {
                ops++;
                x <<= 1;
                best = min(best, ops + dfs(dfs, i + 1, s + x));
            }
            return dp[i][s] = best;
        };
        memset(dp, -1, sizeof(dp));
        int ans = dfs(dfs, 0, 0);
        return ans < INF ? ans : -1;
    }
};
