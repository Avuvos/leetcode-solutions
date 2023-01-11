class Solution {
public:
    vector<vector<int>> g;
    vector<bool> apples;
    //dfs will return how much i have to pay to collect me and return to my parent
    //so for a node who has an apple, its 2 + the cost of his children
    //for a node who doesnt have an apple, its just the cost of his children
    int dfs(int u, int p) {
        int cost = 0;
        for (auto v: g[u]) {
            if (v == p) continue;
            int cur = dfs(v, u);
            if (cur > 0 || apples[v]) {
                cost += 2 + cur;
            }
        }
        return cost;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g = vector<vector<int>>(n);
        apples = hasApple;
        for (int i = 0; i < n - 1; i++) {
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        return dfs(0, -1);
        
    }
};
