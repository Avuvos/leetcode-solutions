class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1 << 14][15];
    int specialPerm(vector<int>& nums) {
        int n = (int) nums.size();
        memset(dp, -1, sizeof(dp));
        function<long long(int, int)> dfs = [&](int mask, int prev) -> long long {
            if (dp[mask][prev] != -1) return dp[mask][prev];
            
            long long ans = 0;
            bool tookAll = true;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) continue;
                tookAll = false;
                if (prev == n || nums[prev] % nums[i] == 0 || nums[i] % nums[prev] == 0) {
                    int next_mask = mask | (1 << i);
                    ans += dfs(next_mask, i);
                    ans %= MOD;
                }
            }
            if (tookAll) return 1;
            dp[mask][prev] = ans % MOD;
            return ans;
        };
        
        return dfs(0, n);
    }
};
