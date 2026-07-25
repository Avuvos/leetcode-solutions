class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> seen(n);
        for (int mask = 1; mask < (1 << n); mask++) {
            int sum = 0, start = -1;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    sum += nums[i];
                    start = i;
                }
            }
            if (sum % 2 == 1) continue;
            seen.assign(n, false);
            auto dfs = [&](auto& dfs, int u) -> void {
                seen[u] = true;
                for (auto &v: g[u]) {
                    if (((mask >> v) & 1) && !seen[v]) {
                        dfs(dfs, v);
                    }
                }
            };
            dfs(dfs, start);
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) && !seen[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
        return ans;
    }
};
