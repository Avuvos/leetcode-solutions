class Solution {
public:
    
    vector<int> ans;
    vector<vector<int>> g;
    string label;
    int dfs(int u, int p, char c) {
        int res = 0;
        if (label[u] == c) res++;
        for (auto v: g[u]) {
            if (v == p) continue;
            res += dfs(v, u, c);
        }
        if (label[u] == c) {
            ans[u] = res;
        }
        return res;
    }
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){
        ans = vector<int>(n, 0);
        g = vector<vector<int>>(n);
        label = labels;
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        string ab = "abcdefghijklmnopqrstuvwxyz";
        for (auto c: ab) {
            dfs(0, -1, c);
        }
        return ans;
    }
};
