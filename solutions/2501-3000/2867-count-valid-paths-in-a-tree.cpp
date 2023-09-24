class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<int> is_prime(n + 1, 1);
        is_prime[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        
        long long ans = 0;
        function<pair<int, int>(int, int)> dfs = [&](int u, int p) {
            int u0 = 1 - is_prime[u];
            int u1 = is_prime[u];
            for (auto &v: g[u]) {
                if (v == p) continue;
                auto [v0, v1] = dfs(v, u);
                ans += 1LL * u1 * v0;
                ans += 1LL * u0 * v1;
                if (is_prime[u]) {
                    u1 += v0;
                } else {
                    u0 += v0;
                    u1 += v1;
                }
            }
            return make_pair(u0, u1);
        };
        dfs(1, -1);
        return ans;
    }
};
