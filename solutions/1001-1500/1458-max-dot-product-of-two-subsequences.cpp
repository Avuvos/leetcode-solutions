class Solution {
public:
    typedef long long ll;
    const ll INF = 1e16;
    ll dp[501][501][2];
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -INF;
                }
            }
        }
        
        function<ll(int, int, int)> dfs = [&](int i, int j, int took) -> ll {
            if (i >= n || j >= m) {
                return took ? 0 : -INF;
            }
            if (dp[i][j][took] != -INF) {
                return dp[i][j][took];
            }
            return dp[i][j][took] = max({dfs(i + 1, j, took), dfs(i, j + 1, took), 
                                        a[i]*b[j] + dfs(i + 1, j + 1, 1)});
        };
        return dfs(0, 0, 0);
    }
};
