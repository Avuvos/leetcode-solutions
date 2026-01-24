class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size(), v = 0, mod = 1e9 + 7;
        long long ans = 0;

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        vector<unordered_map<int, long long>> dp_sum(2);
        dp_sum[1][0] = 1;

        for (int i = 0; i < n; i++) {
            v ^= nums[i];
            dp[i + 1][0] = (dp[i + 1][0] + dp_sum[1][v ^ target1]) % mod;
            dp[i + 1][1] = (dp[i + 1][1] + dp_sum[0][v ^ target2]) % mod;
            dp_sum[0][v] = (dp_sum[0][v] + dp[i + 1][0]) % mod;
            dp_sum[1][v] = (dp_sum[1][v] + dp[i + 1][1]) % mod;
        }
        return (dp[n][0] + dp[n][1]) % mod;
    }
};

// dp[i][0] -> num of partitions where last block xor is t1
// dp[i][1] -> num of partitions where last block xor is t2

// dp[0][1] = 1 is the base case

// let ps[i] = xor up to i not inclusive, so xor[i..j] = ps[i + 1] ^ ps[j]

// dp[i][0] += sum(dp[j][1]) when j: (xj+1  .... ^xi) = t1
// -> ps[i + 1] ^ ps[j + 1] = t1
// -> ps[j + 1] = t1 ^ ps[i + 1]
// so we need a hashmap to save how many positions have this value of ps[j] and we are done I think?



