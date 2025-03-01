class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> rg(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            rg[v].emplace_back(u, w);
        }
        vector<bool> seen(n, false);
        
        auto ok = [&](int x) -> bool {
            for (int i = 0; i < n; i++) seen[i] = false;
            
            auto dfs = [&](auto &dfs, int u) -> void {
                seen[u] = true;
                for (auto &[v, w]: rg[u]) {
                    if (seen[v] || w > x) continue;
                    dfs(dfs, v);
                }
            };
            dfs(dfs, 0);
            return all_of(seen.begin(), seen.end(), [&](int x) {return x;});
            
        };

        
        int left = 0, right = 1e6, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ok(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
        
                
    }
};
