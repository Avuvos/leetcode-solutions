class Solution {
public:
    
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        // dp[u][s][2] - count of subsets of subtree of u where sum is s%k and u participates or not
        // result is dp[0][0][0] + dp[0][0][1]
        // perform post-order dfs and merge children to root  
        int n = parent.size(), mod = 1e9 + 7;;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k, vector<long long>(2, 0)));
        auto dfs = [&](auto &dfs, int u, int p) -> void {
            dp[u][0][0] = 1;
            dp[u][nums[u] % k][1] = 1;
            for (auto &v: g[u]) {
                dfs(dfs, v, u);
                vector<long long> ndp0(k, 0), ndp1(k, 0);
                for (int x = 0; x < k; x++) {
                    if (dp[v][x][0] == 0 && dp[v][x][1] == 0) continue;
                    for (int y = 0; y < k; y++) {
                        int t = (y + x) % k;
                        ndp0[t] = (ndp0[t] + (dp[v][x][0] + dp[v][x][1]) * dp[u][y][0] % mod) % mod;
                        ndp1[t] = (ndp1[t] + (dp[v][x][0] * dp[u][y][1] % mod)) % mod;
                    }
                }
                for (int i = 0; i < k; i++) {
                    dp[u][i][0] = ndp0[i];
                    dp[u][i][1] = ndp1[i];
                }
            }
        };
        dfs(dfs, 0, -1);
        return (dp[0][0][0] + dp[0][0][1] - 1) % mod;
    }
};
