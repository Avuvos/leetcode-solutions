class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        unordered_map<int, int> group_counter;
        for (int i = 0; i < n; i++) {
            group_counter[group[i]]++;
        }
        long long ans = 0;
        auto dfs = [&](auto &dfs, int u, int p) -> unordered_map<int, int> {
            unordered_map<int, int> counts = {{group[u], 1}};
            for (auto &v: g[u]) {
                if (v == p) continue;
                auto child_counts = dfs(dfs, v, u);
                for (auto [key, val]: child_counts) {
                    ans += 1LL * (group_counter[key] - val) * val;
                    counts[key] += val;
                }
            }
            return counts;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
