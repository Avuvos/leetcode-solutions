class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = (int) graph.size();
        int target = (1 << n) - 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(1 << n, false));
        for (int i = 0; i < n; i++) {
            q.push(make_pair(i, 1 << i));
            seen[i][1 << i] = true;
        }
        int ans = 0;
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int iter = 0; iter < sz; iter++) {
                auto [node, mask] = q.front(); q.pop();
                if (mask == target) {
                    return ans;
                }
                for (auto &nei: graph[node]) {
                    int next_mask = mask | (1 << nei);
                    if (!seen[nei][next_mask]) {
                        q.push(make_pair(nei, next_mask));
                        seen[nei][next_mask] = true;
                    }
                }
            }
            ans++;
        }
        assert(false);
        return -1;
    }
};
