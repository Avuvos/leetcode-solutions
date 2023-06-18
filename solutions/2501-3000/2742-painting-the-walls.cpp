class Solution {
public:
    const int INF = 1e9;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = (int) cost.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int index = 0; index < n; index++) {
            for (int walls = n; walls >= 1; walls--) {
                dp[walls] = min(dp[walls], dp[max(0, walls - time[index] - 1)] + cost[index]);
            }
        }
        return dp[n];
    }
};
