class Solution {
public:
    int n, m;
    long long dp[55][55][15];
    const int MOD = 1e9 + 7;
    int hasApple(int minRow, int maxRow, int minCol, int maxCol, vector<string>& pizza) {
        for (int i = minRow ; i < maxRow; i++) {
            for (int j = minCol; j < maxCol; j++) {
                if (pizza[i][j] == 'A') return 1;
            }
        }
        return 0;
    }
    long long dfs(int row, int col, int cuts, vector<string>& pizza) {
        if (cuts == 0) return hasApple(row, n, col, m, pizza);
        if (dp[row][col][cuts] != 0) return dp[row][col][cuts];
        long long ans = 0;
        for (int i = row + 1; i < n; i++) {
            if (hasApple(row, i, col, m, pizza) && hasApple(i, n, col, m, pizza)) {
                ans += dfs(i, col, cuts - 1, pizza);
                ans %= MOD;
            }
        }
        for (int i = col + 1; i < m; i++) {
            if (hasApple(row, n, col, i, pizza) && hasApple(row, n, i, m, pizza)) {
                ans += dfs(row, i, cuts - 1, pizza);
                ans %= MOD;
            }
        }
        dp[row][col][cuts] = ans % MOD;
        return dp[row][col][cuts];
    }

    int ways(vector<string>& pizza, int k) {
        //dp[i][j][k], our grid is from rows[i:n] and cols[j:m], and we have k cuts left.
        n = (int) pizza.size(), m = (int) pizza[0].size();
        if (k - 1 > n - 1 + m - 1) return 0;
        memset(dp, 0, sizeof(dp));
        return dfs(0, 0, k - 1, pizza) % MOD;
    }
};
