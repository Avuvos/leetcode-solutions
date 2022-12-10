typedef priority_queue<int,vector<int>,greater<int>> min_priority_queue;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<min_priority_queue> adj(n + 1);
        vector<long long> sums(n + 1, 0);
        for (auto& e: edges) {
            if (vals[e[1]] > 0) {
                adj[e[0]].push(vals[e[1]]);
                sums[e[0]] += vals[e[1]];   
            }
            if (vals[e[0]] > 0) {
                adj[e[1]].push(vals[e[0]]);
                sums[e[1]] += vals[e[0]];
            }
            if (adj[e[0]].size() > k) {
                sums[e[0]] -= adj[e[0]].top();
                adj[e[0]].pop();
            }
            if (adj[e[1]].size() > k) {
                sums[e[1]] -= adj[e[1]].top();
                adj[e[1]].pop();
            }
        }
        long long res = vals[0];
        for (int i = 0; i < n; i++) {
            res = max(res, sums[i] + vals[i]);
        }
        return res;
    }
};
