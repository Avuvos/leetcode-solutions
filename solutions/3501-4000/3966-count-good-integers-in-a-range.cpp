class Solution {
public:
    long long dp[17][2][2][10];
    long long goodIntegers(long long l, long long r, int k) {
        
        auto dfs = [&](auto &dfs, string &s, int i, int t, int z, int p) -> long long {
            if (i >= s.size()) {
                return 1;
            }
            if (dp[i][t][z][p] != -1) {
                return dp[i][t][z][p];
            }
            int bound = t ? (s[i] - '0') : 9;
            long long ans = 0;
            for (int d = 0; d <= bound; d++) {
                if (!z && abs(d - p) > k) continue;
                int nt = t && d == (s[i] - '0');
                int nz = z && d == 0;
                ans += dfs(dfs, s, i + 1, nt, nz, d);
            }
            return dp[i][t][z][p] = ans;
        };
        string low = to_string(l - 1), high = to_string(r);

        memset(dp, -1, sizeof(dp));
        long long ansHigh = dfs(dfs, high, 0, 1, 1, 0);

        memset(dp, -1, sizeof(dp));
        long long ansLow = dfs(dfs, low, 0, 1, 1, 0);

        return ansHigh - ansLow;
    }
};
