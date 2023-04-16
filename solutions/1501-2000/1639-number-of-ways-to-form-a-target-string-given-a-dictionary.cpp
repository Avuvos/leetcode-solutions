class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int n = (int) words[0].size(), m = target.size();
        vector<vector<long long>> dp(n + 1,vector<long long>(m + 1, -1));
        vector<vector<long long>> counter(n, vector<long long>(26, 0));
        for (auto &word: words) {
            for (int i = 0; i < n; i++) {
                counter[i][word[i] - 'a']++;
            }
        }

        function<long long(int index, int target_index)> dfs = [&](int index, int target_index)-> long long {
            if (target_index >= m) return 1;
            if (index >= n) return 0;
            if (dp[index][target_index] != -1) return dp[index][target_index];
            long long ans = 0;
            ans += dfs(index + 1, target_index) % mod;
            char current = target[target_index];
            long long cnt = counter[index][current - 'a'];
            if (cnt > 0) ans += (cnt * dfs(index + 1, target_index + 1)) % mod;
            dp[index][target_index] = ans % mod;
            return dp[index][target_index];
        };
        return dfs(0, 0);
    }
};
