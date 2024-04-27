class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> prefix_dp_one(one + 1, vector<long long>(zero + 1, 0));
        vector<vector<long long>> prefix_dp_zero(one + 1, vector<long long>(zero + 1, 0));
        vector<vector<vector<long long>>> dp(one + 1, vector<vector<long long>>(zero + 1, vector<long long>(2, 0)));
        for (int i = 0; i <= one; i++) {
            dp[i][0][1] = i <= limit ? 1 : 0; 
            prefix_dp_one[i][0] = dp[i][0][1];
        }
        for (int i = 0; i <= zero; i++) {
            dp[0][i][0] = i <= limit ? 1 : 0; 
            prefix_dp_zero[0][i] = dp[0][i][0];
        }
       
        for (int i = 1; i <= one; i++) {
            for (int j = 1; j <= zero; j++) {
                
                dp[i][j][1] = prefix_dp_zero[i - 1][j] % MOD;
                dp[i][j][0] = prefix_dp_one[i][j - 1] % MOD;
                
                if (i - limit - 1 >= 0) dp[i][j][1] = (dp[i][j][1] - prefix_dp_zero[i - limit - 1][j] + MOD) % MOD;
                if (j - limit - 1 >= 0) dp[i][j][0] = (dp[i][j][0] - prefix_dp_one[i][j - limit - 1] + MOD) % MOD;

                
                prefix_dp_zero[i][j] = (prefix_dp_zero[i - 1][j] + dp[i][j][0]) % MOD;
                prefix_dp_one[i][j] = (prefix_dp_one[i][j - 1] + dp[i][j][1]) % MOD;
                
            }
        }
        return (dp[one][zero][0] + dp[one][zero][1]) % MOD;
        
    }
};
