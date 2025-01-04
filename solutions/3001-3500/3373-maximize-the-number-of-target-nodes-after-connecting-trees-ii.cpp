class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        /*
        first observation is that nodes can only be target of each other if they are on the 
        same parity of the BFS level - by definition.
        so it doesn't really matter who is the root?
        consider some node, there are two options,
        either i connect myself to the MINIMUM level on the other tree, allowing me to get the maximum after traversing one edge.
        or i connect someone else to the maximum? and i pass through him? but those options are the same right..
        so this question is quite silly again.
        */
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        auto build = [&](vector<vector<int>>& edges, vector<vector<int>>& g) {
            for (auto &e: edges) {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
        };
        build(edges1, g1);
        build(edges2, g2);
        auto dfs = [&](auto &dfs, int u, int p, int x, vector<vector<int>>& g, vector<int>& layer, vector<int>& counts) -> void {
            layer[u] = x;
            counts[x]++;
            for (auto &v: g[u]) {
                if (v == p) continue;
                dfs(dfs, v, u, x ^ 1, g, layer, counts);
            }
        };
        vector<int> layer1(n), layer2(m);
        vector<int> counts1(2, 0), counts2(2, 0);
        dfs(dfs, 0, 0, 0, g1, layer1, counts1);
        dfs(dfs, 0, 0, 0, g2, layer2, counts2);
        vector<int> ans(n, max(counts2[0], counts2[1]));
        for (int i = 0; i < n; i++) {
            ans[i] += counts1[layer1[i]];
        }
        return ans;
    }
};
