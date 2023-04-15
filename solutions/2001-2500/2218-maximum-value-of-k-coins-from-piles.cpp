class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = (int) piles.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        function <int(int, int)> dfs = [&](int index, int coins) {
            if (coins <= 0 || index >= n) return 0;
            if (dp[index][coins] != -1) return dp[index][coins];
            int sum = 0, res = 0;
            res = max(res, dfs(index + 1, coins));
            for (int i = 0; i < piles[index].size() && coins - (i + 1) >= 0; i++) {
                sum += piles[index][i];
                res = max(res, dfs(index + 1, coins - (i + 1)) + sum);
            }
            dp[index][coins] = res;
            return res;
        };
        return dfs(0, k);
    }
};
