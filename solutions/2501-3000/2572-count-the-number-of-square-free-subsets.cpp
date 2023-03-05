class Solution {
public:
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int dp[1001][(1 << 12) + 1];
    const int MOD = 1e9 + 7;
    int dfs(int index, int mask, vector<int>& nums) {
        if (index >= nums.size()) {
            return mask > 0;
        }
        if (dp[index][mask] != -1) {
            return dp[index][mask];
        }
        bool can_take = true;
        int next_mask = mask | 1;
        int num = nums[index];
        for (int i = 0; i < primes.size(); i++) {
            if (num % primes[i] == 0) {
                if ((mask >> (i + 1)) & 1) {
                    can_take = false;
                    break;
                }
                next_mask |= (1 << (i + 1));
                num /= primes[i];
                if (num % primes[i] == 0) {
                    can_take = false;
                    break;
                }
            }
        }
        int take = 0, skip = 0;
        if (can_take) {
            take = dfs(index + 1, next_mask, nums);
        }
        skip = dfs(index + 1, mask, nums);
        take %= MOD;
        skip %= MOD;
        dp[index][mask] = (take + skip) % MOD;
        return dp[index][mask];
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, nums);
    }
};
