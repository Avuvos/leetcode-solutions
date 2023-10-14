class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        
        auto ham = [&](string s, string t) {
            if (s.size() != t.size()) return 0;
            int cnt = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) {
                    cnt++;
                }
            }
            return cnt;
        };
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> parent(n + 1, vector<int>(n + 1, -1));
        auto dfs = [&](auto dfs, int index, int prev) -> int {
            if (index >= n) {
                return 0;
            }
            if (dp[index][prev] != -1) {
                return dp[index][prev];
            }
            int take = 0;
            int skip = dfs(dfs, index + 1, prev);
            if ((prev == n) || (groups[index] != groups[prev] && ham(words[index], words[prev]) == 1)) {
                take = 1 + dfs(dfs, index + 1, index);
            }
            if (take > skip) {
                parent[index][prev] = 0;
            } else {
                parent[index][prev] = 1;
            }
            return dp[index][prev] = max(take, skip);
        };
        dfs(dfs, 0, n);
        int i = 0, j = n;
        while (i < n) {
            if (parent[i][j] == 0) {
                j = i;
                ans.push_back(words[i]);
            }
            i++;
        }
        return ans;
    }
};
