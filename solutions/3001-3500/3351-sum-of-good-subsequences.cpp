class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end()) + 3;
        vector<long long> dp(m, 0), cnt(m, 0);
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            cnt[x]++;
            dp[x] += x;
            if (x + 1 < m) {
                cnt[x] = (cnt[x] + cnt[x + 1]) % MOD;
                dp[x] = (dp[x] + dp[x + 1] + 1LL * x * cnt[x + 1] % MOD) % MOD;
            }
            if (x - 1 >= 0) {
                cnt[x] = (cnt[x] + cnt[x - 1]) % MOD;
                dp[x] = (dp[x] + dp[x - 1] + 1LL * x * cnt[x - 1] % MOD) % MOD;
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
