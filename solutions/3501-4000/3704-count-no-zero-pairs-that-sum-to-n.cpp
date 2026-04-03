class Solution {
public:
    long long dp[17][2][2][2];
    long long countNoZeroPairs(long long n) {
        
        auto dfs = [&](auto &dfs, string &s, int i, int c, int az, int bz) -> long long {
            if (i >= s.size()) {
                return c == 0; // Carry must be 0
            }
            if (dp[i][c][az][bz] != -1) {
                return dp[i][c][az][bz];
            }
            int t = s[i] - '0';
            long long ans = 0;
            for (int a = 0; a <= 9; a++) {
                if ((a != 0 && az) || (a == 0 && i == 0)) continue;
                for (int b = 0; b <= 9; b++) {
                    if ((b != 0 && bz) || (b == 0 && i == 0)) continue;
                    int sum = (a + b + c);
                    if (sum % 10 == t) {
                        int nc = sum / 10;
                        int naz = az | (a == 0);
                        int nbz = bz | (b == 0);
                        ans += dfs(dfs, s, i + 1, nc, naz, nbz);
                    }
                }
            }
            return dp[i][c][az][bz] = ans;
        };

        string s = to_string(n);
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return dfs(dfs, s, 0, 0, 0, 0);
    }
};
