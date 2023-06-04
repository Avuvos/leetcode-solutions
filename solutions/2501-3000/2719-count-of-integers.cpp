class Solution {
public:
    typedef long long ll;
    const int MAX_SIZE = 23, MAX_SUM = 401, MOD = 1e9 + 7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        while (num1.size() < num2.size()) {
            num1 = "0" + num1;
        }
        ll dp[MAX_SIZE][MAX_SUM][2][2];
        function<long long(int, int, bool, bool)> dfs = [&](int idx, int sum, bool t1, bool t2)-> ll {
            if (sum < 0) return 0;
            if (idx >= num2.size()) return 1;
            if (dp[idx][sum][t1][t2] != -1) return dp[idx][sum][t1][t2];

            int low = (t1 ? num1[idx] - '0' : 0);
            int high = (t2 ? num2[idx] - '0' : 9);

            ll ans = 0;
            for (int digit = low; digit <= high; digit++) {
                ans += dfs(idx + 1, sum - digit, t1 && (digit == num1[idx] - '0'), t2 && (digit == num2[idx] - '0'));
                ans %= MOD;
            }
            dp[idx][sum][t1][t2] = ans;
            return ans;
        };

        memset(dp, -1, sizeof(dp));
        ll upper = dfs(0, max_sum, true, true);

        memset(dp, -1, sizeof(dp));
        ll lower = dfs(0, min_sum - 1, true, true);
        
        return (upper - lower + MOD) % MOD;

    }
};
