class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        //dfs to find depth/set parent for each node
        function<void(int, int, int)> dfs1 = [&](int u, int p, int d) {
            parent[u] = p;
            depth[u] = d;
            for (auto &v: g[u]) {
                if (v == p) continue;
                dfs1(v, u, d + 1);
            }
        };
        //root the tree at node 0
        dfs1(0, -1, 0); 
        
        //how many times each node price will be used
        vector<int> freq(n, 0); 
        for (auto &trip: trips) {
            int a = trip[0], b = trip[1];
            while (a != b) {
                if (depth[a] > depth[b]) {
                    freq[a]++;
                    a = parent[a];
                } else {
                    freq[b]++;
                    b = parent[b];
                }
            }
            freq[a]++;
        }
        
        //calc the "dp",for each node either take the half price (if u can), or skip it
        function<pair<int, int>(int, int)> dfs2 = [&](int u, int p) {
            pair<int, int> ans = {price[u]*freq[u]/2, price[u]*freq[u]};
            for (auto &v: g[u]) {
                if (v == p) continue;
                pair<int, int> child_ans = dfs2(v, u);
                ans.first += child_ans.second;
                ans.second += min(child_ans.first, child_ans.second);
            }
            return ans;
        };
        pair<int, int> ans = dfs2(0, -1);
        return min(ans.first, ans.second);
    }
};
