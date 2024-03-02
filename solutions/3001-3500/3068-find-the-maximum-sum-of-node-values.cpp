class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = (int) edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        const int inf = 1e9 + 12;
        auto dfs = [&](auto dfs, int u, int p) -> pair<long long, long long>{
            long long with_xor, no_xor;
            vector<array<long long, 4>> d;
            long long sum_best = 0;
            for (auto &v: g[u]) {
                if (v == p) continue;
                auto [child_xor, no_child_xor] = dfs(dfs, v, u);
                d.push_back({max(child_xor - (nums[v]^k) + nums[v], no_child_xor - nums[v] + (nums[v]^k)) - max(child_xor, no_child_xor), child_xor, no_child_xor, nums[v]});
                sum_best += max(child_xor, no_child_xor);
            }
            sort(d.rbegin(), d.rend());
            
            no_xor = sum_best + nums[u];
            with_xor = -inf;
        
            long long sum = 0;
            for (int i = 0; i < d.size(); i++) {
                auto [diff, xor_val, no_xor_val, val] = d[i];
                sum += max(xor_val - (val^k) + val, no_xor_val - val + (val^k));
                sum_best -= max(xor_val, no_xor_val);
                if (i % 2 == 0) {
                    //affects with xor
                    with_xor = max(with_xor, (k^nums[u]) + sum + sum_best);
                } else {
                    //affects without xor on myself
                    no_xor = max(no_xor, nums[u] + sum + sum_best);
                }
            }
            return {with_xor, no_xor};
        };
        auto ans = dfs(dfs, 0, -1);
        return max(ans.first, ans.second);
    }
};
