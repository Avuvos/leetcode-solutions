class Solution {
public:
    long long memo[1001][101][2];
    long long dfs(int index, int k, bool buying, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }
        if (memo[index][k][buying] != -1) {
            return memo[index][k][buying];
        }
        long long take = 0, skip = 0, sell = 0;
        if (k > 0 && !buying)
            take = dfs(index + 1, k - 1, !buying, prices) - prices[index];
        if (buying)
            sell = dfs(index + 1, k, !buying, prices) + prices[index];
        skip = dfs(index + 1, k, buying, prices);
        memo[index][k][buying] = max(max(take, skip), sell);
        return memo[index][k][buying];
    }

    int maxProfit(int k, vector<int>& prices) {
        fill_n(&memo[0][0][0], 1001*101*2, -1);
        return dfs(0, k, false, prices);
    }
};
