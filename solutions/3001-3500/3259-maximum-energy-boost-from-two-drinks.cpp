class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n = (int) A.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        auto dfs = [&](auto &dfs, int index, int last) -> long long {
            if (index >= n) {
                return 0;
            }
            if (dp[index][last] != -1) {
                return dp[index][last];
            }
            long long ans = 0;
            if (last == 0) {
                long long stay = A[index] + dfs(dfs, index + 1, 0);
                long long move = A[index] + dfs(dfs, index + 2, 1);
                ans = max(stay, move);
            } else {
                long long stay = B[index] + dfs(dfs, index + 1, 1);
                long long move = B[index] + dfs(dfs, index + 2, 0);
                ans = max(stay, move);
            }
            return dp[index][last] = ans;
        };
        
        return max(dfs(dfs, 0, 0), dfs(dfs, 0, 1));
    }
};
