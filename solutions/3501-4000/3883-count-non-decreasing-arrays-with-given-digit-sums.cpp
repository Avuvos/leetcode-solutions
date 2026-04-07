// 0 <= arr[i] <= 5000 + dig_sum(arr[i]) = digitsSum[i]
// does not leave alot of choices for arr[i]
// perhaps we can pre calc all the possible values that sum to each digit usm.
// then dp[i][c] is the number of valid arrays up to i, that end on c.
// to calc it, one simply needs to sum dp[i - 1][k] for each k <= c.
// but we KNOW that only a FEW k values are valid due to the digitSum constraint, so brute force it.

class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size(), m = 5001, s = 51, mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> values(s);
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0, x = j;
                while (x > 0) {
                    sum += x % 10;
                    x /= 10;
                }
                if (sum == i) {
                    values[i].push_back(j);
                }
            }
        }


        for (auto &v: values[digitSum[0]]) {
            dp[0][v] = 1;
        }


        for (int i = 1; i < n; i++) {
            auto &prev = values[digitSum[i - 1]];
            int p = 0, ps = 0;
            for (auto &x: values[digitSum[i]]) {
                while (p < prev.size() && prev[p] <= x) {
                    ps = (ps + dp[i - 1][prev[p]]) % mod;
                    p++;
                }
                dp[i][x] = (dp[i][x] + ps) % mod;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + dp[n - 1][i]) % mod;
        }
        return ans;
    }
};
