class Solution {
public:
    long long dp[17][500][2][3][2];
    const int OFFSET = 200;
    long long countBalanced(long long low, long long high) {
        auto dfs = [&](auto &dfs, string s, int i, int sum, int tight, int took, int si) -> long long {
            if (i >= s.size()) {
                return sum == 0 && took == 2;
            }
            if (dp[i][sum + OFFSET][tight][took][si] != -1) {
                return dp[i][sum + OFFSET][tight][took][si];
            }
            int up = tight ? s[i] - '0' : 9;
            long long ans = 0;
            for (int d = 0; d <= up; d++) {
                if (took == 0 && d == 0) {
                    ans += dfs(dfs, s, i + 1, 0, 0, 0, 0);
                    continue;
                }
                int ntight = tight && (d == (s[i] - '0'));
                int nsum = sum + (si == 0 ? -d : d);
                int ntook = min(took + 1, 2);
                int nsi = si ^ 1;
                ans += dfs(dfs, s, i + 1, nsum, ntight, ntook, nsi);
            }
            return dp[i][sum + OFFSET][tight][took][si] = ans;
        };
        memset(dp, -1, sizeof(dp));
        long long r = dfs(dfs, to_string(high), 0, 0, 1, 0, 0);
        memset(dp, -1, sizeof(dp));
        long long l = dfs(dfs, to_string(low - 1), 0, 0, 1, 0, 0);
        return r - l;
    }
};
