class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        //dp(index, sum, cnt) -> O(n^3) index <= n, sum <= k+1, cnt <= n
        int n = (int) nums.size();
        vector<long long> two_pow(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            two_pow[i] = (2 * two_pow[i - 1]) % MOD;
        }
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 2, vector<long long>(n + 1, -1)));
        auto dfs = [&](auto dfs, int index, int sum, int cnt) -> long long {
            if (sum > k) {
                return 0LL;
            }
            if (sum == k) {
                return two_pow[n - cnt];
            }
            if (index >= n) {
                return 0LL;
            }
            if (dp[index][sum][cnt] != -1) {
                return dp[index][sum][cnt];
            } 
            long long take = dfs(dfs, index + 1, min(k + 1, nums[index] + sum), cnt + 1) % MOD;
            long long skip = dfs(dfs, index + 1, sum, cnt) % MOD;
            return dp[index][sum][cnt] = (take + skip) % MOD;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};
