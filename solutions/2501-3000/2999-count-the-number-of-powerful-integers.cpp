class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long dp[17][2];
        auto dfs = [&](auto dfs, string &t, int index, int tight) -> long long {
            if (t.size() < s.size()) {
                return 0;
            }
            if (t.size() == s.size()) {
                return t >= s;
            }
            if (index == t.size() - s.size()) {
                return (t.substr(index) >= s) || (tight == 0);
            }
            if (dp[index][tight] != -1) {
                return dp[index][tight];
            }
            int bound = min(limit, tight ? t[index] - '0' : 9);
            long long ans = 0;
            for (int digit = 0; digit <= bound; digit++) {
                ans += dfs(dfs, t, index + 1, tight & (t[index] - '0') == digit);
            }
            return dp[index][tight] = ans;
        };
        string left = to_string(start - 1);
        string right = to_string(finish);
        memset(dp, -1, sizeof(dp));
        long long ansRight = dfs(dfs, right, 0, 1);
        memset(dp, -1, sizeof(dp));
        long long ansLeft = dfs(dfs, left, 0, 1);
        return ansRight - ansLeft;
    }
};
