class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        function<int(int, int)> dfs = [&](int u, int p) {
            long long sum = values[u];
            for (auto &v: g[u]) {
                if (v == p) continue;
                long long cs = dfs(v, u);
                if (cs % k == 0) {
                    ans++;
                } else {
                    sum += cs;
                }
            }
            return sum;
        };
        dfs(0, -1);
        return ans + 1;
    }
};
