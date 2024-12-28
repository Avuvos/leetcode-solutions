class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        
        /*
        dp[i][0] - best score for subtree of i where we DID NOT disconnect edge to parent
        dp[i][1] - best score for subtree of i where we DID disconnect edge to parent
        using dp values of the children, how to calculate self?
        we either need to remove x edges or x - 1 (depending on dp[i][0] or dp[i][1]) (or 0)
        let's calculate the values we get from each child `j` if we remove it or not.
        if we remove it, we get simply dp[j][1]
        if we do not remove it, then we get w[i][j] + dp[j][0]
        how to choose now x children to remove?
        when do we remove child a over child b?
        simply when removing a and taking b would give us larger value than removing b and taking a
        that is: dp[a][1] + w[i][b] + dp[b][0] > dp[b][1] + w[i][a] + dp[a][0]
        sort by that ^ and win
        */
        
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        auto dfs = [&](auto &dfs, int u, int p) -> void {
            vector<pair<int, int>> childs;
            for (auto &[v, w]: g[u]) {
                if (v == p) continue;
                dfs(dfs, v, u);
                childs.emplace_back(v, w);
            }
            sort(childs.begin(), childs.end(), [&](pair<int, int> v1, pair<int, int> v2) {
               int val1 = dp[v1.first][1] + v2.second + dp[v2.first][0];
               int val2 = dp[v2.first][1] + v1.second + dp[v1.first][0];
               return val1 > val2;
            });
            int m = childs.size();
            auto calc = [&](int edges_left, int idx) -> void {
                for (auto [c, w]: childs) {
                    if (edges_left <= k) {
                        dp[u][idx] += max(dp[c][1], (dp[c][0] + w));
                    } else {
                        dp[u][idx] += (dp[c][1]);
                    }
                    edges_left--;
                }
            };
            calc(m + (u != 0) , 0); // add 1 if u is not the root
            calc(m, 1);
        };
        
        dfs(dfs, 0, -1);
        return dp[0][0];
    }
};
