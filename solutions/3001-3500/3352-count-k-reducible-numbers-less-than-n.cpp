class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int x = i;
            int ops = 0;
            while (x != 1) {
                x = __builtin_popcount(x);
                ops++;
            }
            dp[i] = ops;
        }
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));
        auto dfs = [&](auto &dfs, int index, int ones, int tight) -> long long {
            if (index >= n) {
                return dp[ones] < k && ones > 0 && !tight;
            }
            if (memo[index][ones][tight] != -1) {
                return memo[index][ones][tight];
            }
            long long ans = 0;
            
            long long zero = dfs(dfs, index + 1, ones, tight && (s[index] == '0')) % MOD;
            ans = (ans + zero) % MOD;
            
            if (!tight || s[index] == '1') {
                int nt = tight && s[index] == '1';
                long long one = dfs(dfs, index + 1, ones + 1, nt);
                ans = (ans + one) % MOD;
            }
            
            return memo[index][ones][tight] = ans;
        };
        
        return dfs(dfs, 0, 0, 1);
        
    }
};
