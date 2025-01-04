class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        /*  
        we want to find the node with the maximum number of reachable nodes within k - 1 edges
        and connect that node simply to each node in the first tree
        just brute force it as the constraints allow it?
        */
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto &e: edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e: edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        vector<int> counts(m);
        auto dfs = [&](auto &dfs, int u, int p, int d, vector<vector<int>> &g) -> int {
            if (d < 0) return 0;
            int total = 1;
            for (auto &v: g[u]) {
                if (v == p) continue;
                if (d - 1 >= 0) {
                    total += dfs(dfs, v, u, d - 1, g);
                }
            }
            return total;
        };
        int best_count_other_tree = 0;
        for (int i = 0; i < m; i++) {
            counts[i] = dfs(dfs, i, -1, k - 1, g2);
            best_count_other_tree = max(best_count_other_tree, counts[i]);
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            int cnt = dfs(dfs, i, -1, k, g1);
            answer[i] = cnt + best_count_other_tree;
        }
        return answer;
    }
};
