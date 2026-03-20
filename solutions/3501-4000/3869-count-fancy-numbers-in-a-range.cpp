class Solution {
public:
    static const int M = 146;
    long long dp[16][2][2][10][M][2][2];
    long long countFancy(long long l, long long r) {
        vector<bool> good(M);
        auto is_good = [&](int x) -> bool {
            vector<int> digits;
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
            bool dec = true, inc = true; 
            reverse(digits.begin(), digits.end());
            for (int i = 0; i + 1 < digits.size(); i++) {
                dec &= (digits[i + 1] < digits[i]);
                inc &= (digits[i + 1] > digits[i]);
            }
            return dec || inc;
        };
        for (int i = 0; i < M; i++) {
            good[i] = is_good(i);
        }

        auto dfs = [&](auto &dfs, string s, int i, int t, int zero, int prev, int sum, int inc, int dec) -> long long {
            if (i >= s.size()) {
                return inc || dec || good[sum];
            }
            if (dp[i][t][zero][prev][sum][inc][dec] != -1) {
                return dp[i][t][zero][prev][sum][inc][dec];
            }
            long long ans = 0;
            int bound = t ?(s[i] - '0') : 9;
            for (int d = 0; d <= bound; d++) {
                int ni = i + 1;
                int nt = t && d == (s[i] - '0');
                int nzero = zero && d == 0;
                int nprev = d;
                int nsum = sum + d;
                int ninc = inc && (zero || d > prev);
                int ndec = dec && (zero || d < prev);
                ans += dfs(dfs, s, ni, nt, nzero, nprev, nsum, ninc, ndec);
            }
            return dp[i][t][zero][prev][sum][inc][dec] = ans;
        };
        memset(dp, -1, sizeof(dp));
        long long ansHigh = dfs(dfs, to_string(r), 0, 1, 1, 0, 0, 1, 1);
        memset(dp, -1, sizeof(dp));
        long long ansLow = dfs(dfs, to_string(l - 1), 0, 1, 1, 0, 0, 1, 1);
        return ansHigh - ansLow;
    }
};
