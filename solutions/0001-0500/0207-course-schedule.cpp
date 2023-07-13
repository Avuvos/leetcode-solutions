class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        for (auto &e: pre) {
            g[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        vector<int> done(n, false);
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                done[i] = true;
            }
        }
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto &nei: g[node]) {
                indeg[nei]--;
                if (indeg[nei] == 0) {
                    q.push(nei);
                    done[nei] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!done[i]) {
                return false;
            }
        }
        return true;
    }
};
