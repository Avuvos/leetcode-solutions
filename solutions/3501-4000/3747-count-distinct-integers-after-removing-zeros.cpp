class Solution {
public:
    long long countDistinct(long long n) {
        vector<int> digits;
        long long nx = n;
        while (nx > 0) {
            digits.push_back(nx % 10);
            nx /= 10;
        }
        reverse(digits.begin(), digits.end());

        long long dp[20][2][2][2];
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto &dfs, int i, int tight, int zero, int took) -> long long {
            if (i >= digits.size()) {
                return zero ? 1 : 0;
            }
            if (dp[i][tight][zero][took] != -1) {
                return dp[i][tight][zero][took];
            }
            long long ans = 0;
            int up = tight ? digits[i] : 9;
            for (int d = 0; d <= up; d++) {
                int nti = tight && (d == digits[i]);
                int nt = took | (d != 0);
                int nz = zero | (nt && d == 0);
                ans += dfs(dfs, i + 1, nti, nz, nt);
            }
            return dp[i][tight][zero][took] = ans;
        };
        return n - dfs(dfs, 0, 1, 0, 0);
    }

};
