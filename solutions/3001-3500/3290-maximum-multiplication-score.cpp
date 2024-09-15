class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        const long long INF = 1e15;
        vector<vector<long long>> dp(n, vector<long long>(5, -1));
        auto dfs = [&](auto &dfs, int index, int picked) -> long long {
            if (picked == 4) {
                return 0;
            }
            if (index >= n) {
                return -INF;
            }
            if (dp[index][picked] != -1) {
                return dp[index][picked];
            }
            long long skip = dfs(dfs, index + 1, picked);
            long long take = 1LL * a[picked] * b[index] + dfs(dfs, index + 1, picked + 1);
            return dp[index][picked] = max(skip, take);
        };
        return dfs(dfs, 0, 0);
    }
};
