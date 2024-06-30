class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = (int) edges1.size() + 1, m = (int) edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto &e: edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e: edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        
        
        function<pair<int, int>(int, int, vector<vector<int>>&)> dfs = [&](int u, int p, vector<vector<int>>& g) -> pair<int, int> {
            int depth = 1, diameter = 0;
            int max_child1 = -1, max_child2 = -1;
            for (auto &v: g[u]) {
                if (v == p) continue;
                auto [child_depth, child_diameter] = dfs(v, u, g);
                if (child_depth > max_child1) {
                    max_child2 = max_child1;
                    max_child1 = child_depth;
                } else if (child_depth > max_child2) {
                    max_child2 = child_depth;
                }
                depth = max(depth, 1 + child_depth);
                diameter = max(diameter, child_diameter);
            }
            diameter = max({diameter, 1 + max_child1 + max_child2, depth});
            return make_pair(depth, diameter);
        };
        int d1 = dfs(0, -1, g1).second;
        int d2 = dfs(0, -1, g2).second;
        return max({d1 - 1, d2 - 1, (d1 + 1 - 1) / 2 + (d2 + 1 - 1) / 2 + 1});
        
    }
};
