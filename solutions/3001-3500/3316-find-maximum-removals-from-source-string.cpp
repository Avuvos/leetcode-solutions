class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size(), inf = 1e9 + 2;
        set<int> st(targetIndices.begin(), targetIndices.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto dfs = [&](auto &dfs, int i, int j) -> int {
            if (i >= n) {
                return j >= m ? 0 : -inf;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int take = -inf, skip = -inf;
            if (st.contains(i)) {
                take = 1 + dfs(dfs, i + 1, j);
            }
            int next_j = j < m && source[i] == pattern[j] ? j + 1 : j;
            skip = dfs(dfs, i + 1, next_j);
            return dp[i][j] = max(skip, take);
        };
        return dfs(dfs, 0, 0);
    }
};
