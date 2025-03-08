class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        int best = 0, mn_nodes = 1e6;
        vector<int> depth(50001);
        auto dfs = [&](auto &dfs, int u, int p, int d, int left, vector<int>& ps) -> void {
            int prev_depth = depth[nums[u]];
            depth[nums[u]] = d;
            left = max(left, prev_depth);
            int sum = ps.back() - ps[left];
            if (sum > best || (sum == best && d - left < mn_nodes)) {
                mn_nodes = d - left;
                best = sum;
            }
            for (auto &[v, w]: g[u]) {
                if (v == p) continue;
                ps.push_back(ps.back() + w);
                dfs(dfs, v, u, d + 1, left, ps);
                ps.pop_back();
            }
            depth[nums[u]] = prev_depth;
         };
        
        vector<int> ps = {0};
        dfs(dfs, 0, -1, 1, 0, ps);
        return {best, mn_nodes};
        
    }
};
