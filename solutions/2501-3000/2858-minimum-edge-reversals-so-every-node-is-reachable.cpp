class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<vector<int>> rg(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            rg[e[1]].push_back(e[0]);
        }
        
        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int cnt = 0;
            for (auto &v: g[u]) {
                if (v == p) continue;
                cnt += dfs(v, u);
            }
            for (auto &v: rg[u]) {
                if (v == p) continue;
                cnt++;
                cnt += dfs(v, u);
            }
            return cnt;
        };
        
        vector<int> answer(n, 0);
        answer[0] = dfs(0, -1);
        
        function<void(int, int, int)> dfs2 = [&](int u, int p, int cnt) {
            answer[u] = cnt;
            for (auto &v: g[u]) {
                if (v == p) continue;
                dfs2(v, u, cnt + 1);
            }
            for (auto &v: rg[u]) {
                if (v == p) continue;
                dfs2(v, u, cnt - 1);
            } 
        };
        
        dfs2(0, -1, answer[0]);
        return answer;
    }
};
