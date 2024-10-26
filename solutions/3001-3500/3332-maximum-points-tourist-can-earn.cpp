class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        //repeat n times
        //choose start city i. then each turn we have n + 1 choices.. either move or stay
        //that is going to be done K times.
        //our state would be in that case (city, days) n^2
        //we can do dp[n][k] max value we can get starting from city n with k days left and we're good I think.
        vector<vector<int>> dp(n, vector<int>(k, -1));
        auto dfs = [&](auto &dfs, int city, int days) -> int {
            if (days < 0) {
                return 0;
            }
            if (dp[city][days] != -1) {
                return dp[city][days];
            }
            int best = stayScore[k - 1 - days][city] + dfs(dfs, city, days - 1);
            for (int i = 0; i < n; i++) {
                if (i == city) continue;
                int go = travelScore[city][i] + dfs(dfs, i, days - 1);
                best = max(best, go);
            }
            return dp[city][days] = best;
        };
        for (int i = 0; i < n; i++) {
            dfs(dfs, i, k - 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][k - 1]);
        }
        return ans;
    }
};
