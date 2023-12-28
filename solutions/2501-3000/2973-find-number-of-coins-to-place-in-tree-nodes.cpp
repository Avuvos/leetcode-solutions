class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        //for each subtree we calculate 4 values
        //max pos, second max pos, min neg, second min neg
        int n = (int) edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<long long> ans(n);
        auto dfs = [&](auto dfs, int u, int p) -> array<long long, 6> {
            array<long long, 6> cur = {0, 0, 0, 0, 0, 1};
            if (cost[u] > 0) {
                cur[0] = cost[u];
            } else {
                cur[3] = cost[u];
            }
            for (auto &v: g[u]) {
                if (v == p) continue;
                array<long long, 6> child = dfs(dfs, v, u);
                if (child[0] >= cur[0]) {
                    cur[2] = cur[1];
                    cur[1] = cur[0]; 
                    cur[0] = child[0];
                } else if (child[0] >= cur[1]) {
                    cur[2] = cur[1];
                    cur[1] = child[0];
                } else if (child[0] >= cur[2]) {
                    cur[2] = child[0];
                }
                if (child[1] >= cur[1]) {
                    cur[2] = cur[1];
                    cur[1] = child[1];
                } else if (child[1] >= cur[2]) {
                    cur[2] = child[1];
                }
                if (child[2] >= cur[2]) {
                    cur[2] = child[2];
                }
                if (child[3] <= cur[3]) {
                    cur[4] = cur[3];
                    cur[3] = child[3];
                } else if (child[3] <= cur[4]) {
                    cur[4] = child[3];
                }
                if (child[4] <= cur[4]) {
                    cur[4] = child[4];
                }
                cur[5] += child[5];
            }
            long long op1 = cur[0] * cur[1] * cur[2];
            long long op2 = cur[0] * cur[3] * cur[4];
            if (cur[5] < 3) {
                ans[u] = 1;
            } else if (max(op1, op2) < 0) {
                ans[u] = 0;
            } else {
                ans[u] = max(op1, op2);
            }
            return cur;
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
