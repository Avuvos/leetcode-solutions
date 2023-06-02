class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = (int) bombs.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            long long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            for (int j = i + 1; j < n; j++) {
            long long cx = bombs[j][0], cy = bombs[j][1], cr = bombs[j][2];
            long long d = (x - cx) * (x - cx) + (y - cy) * (y - cy);     
                if (d <= r*r) {
                    g[i].push_back(j);
                }
                if (d <= cr*cr) {
                    g[j].push_back(i);
                }
            }
        }

        vector<bool> seen(n, false);
        function<int(int)> dfs = [&](int u) {
            seen[u] = true;
            int cnt = 1;
            for (auto v: g[u]) if (!seen[v]) {
                cnt += dfs(v);
            } 
            return cnt;
        };
        

        int ans = 0;
        for (int i = 0; i < n; i++) {
            seen.assign(n, false);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
