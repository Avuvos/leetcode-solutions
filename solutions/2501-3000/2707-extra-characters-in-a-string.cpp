class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = (int) s.size();
        vector<int> dp(n, -1);
        auto dfs = [&](auto &dfs, int index) {
            if (index >= n) {
                return 0;
            }
            if (dp[index] != -1) {
                return dp[index];
            }
            int ans = 1 + dfs(dfs, index + 1);
            for (auto &w: dictionary) {
                int m = (int) w.size();
                if (index + m <= n && s.substr(index, m) == w) {
                    ans = min(ans, dfs(dfs, index + m));
                } 
            }
            return dp[index] = ans;
        };
        return dfs(dfs, 0);
    }
};
