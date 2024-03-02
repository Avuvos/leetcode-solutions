class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = (int) edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(make_pair(e[1], e[2]));
            g[e[1]].push_back(make_pair(e[0], e[2]));
        }
        
        
        auto calc = [&](int node) -> int {
            int ans = 0;
            auto dfs = [&](auto dfs, int u, int p, int sum) -> int {
                int count = sum == 0;
                vector<int> counts;
                for (auto &[v, w]: g[u]) {
                    if (v == p) continue;
                    int count_child = dfs(dfs, v, u, (sum + w) % signalSpeed);
                    if (count_child > 0) {
                        counts.push_back(count_child);
                    }
                    count += count_child;
                }
                if (u == node) {
                    int sum = 0;
                    for (auto &x: counts) {
                        ans += sum * x;
                        sum += x;
                    }
                }
                return count;
            };
            dfs(dfs, node, -1, 0);
            return ans;
        };
        
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = calc(i);
        }
        return ans;
        
    }
};
