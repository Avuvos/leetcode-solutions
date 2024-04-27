class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(one + 1, vector<vector<long long>>(zero + 1, vector<long long>(2, 0)));
        
        for (int i = 0; i <= one; i++) {
            dp[i][0][1] = i <= limit ? 1 : 0; 
        }
        for (int i = 0; i <= zero; i++) {
            dp[0][i][0] = i <= limit ? 1 : 0; 
        }
       
        for (int i = 1; i <= one; i++) {
            for (int j = 1; j <= zero; j++) {
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    dp[i][j][1] += dp[i - k][j][0];
                    dp[i][j][1] %= MOD;
                }
                for (int k = 1; k <= limit && j - k >= 0; k++) {
                    dp[i][j][0] += dp[i][j - k][1];
                    dp[i][j][0] %= MOD;
                }
            }
        }
        return (dp[one][zero][0] + dp[one][zero][1]) % MOD;
        
    }
};
