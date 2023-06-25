class Solution {
public:
    typedef long long ll;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = (int) locations.size();
        ll dp[101][201];
        memset(dp, -1, sizeof(dp));
        ll MOD = 1e9 + 7;
        //dp[i][j] - number of paths from start to i, with j fuel left.
        function<ll(int, int)> dfs = [&](int city, int fuel) -> ll {
            if (fuel == 0) {
                return (city == finish ? 1 : 0);
            }
            if (dp[city][fuel] != -1) {
                return dp[city][fuel];
            }
            ll paths = 0;
            if (city == finish) paths++;
            
            for (int j = 0; j < n; j++) {
                if (j == city) continue;
                ll delta = abs(locations[j] - locations[city]);
                if (fuel - delta >= 0) {
                    paths += dfs(j, fuel - delta);
                    paths %= MOD;
                }
            }
            dp[city][fuel] = paths % MOD;
            return paths;
        };
        return dfs(start, fuel);
    }
};
