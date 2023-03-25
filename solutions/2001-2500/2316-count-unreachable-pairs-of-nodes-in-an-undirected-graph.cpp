class Solution {
public:
    void dfs(int u, int c, vector<bool> &seen, vector<vector<int>>& g, vector<long long>& compSize) {
        compSize[c]++;
        seen[u] = true;
        for (auto &v: g[u]) {
            if (!seen[v])
                dfs(v, c, seen, g, compSize);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g = vector<vector<int>>(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> seen(n, false);
        vector<long long> compSize(n, 0);
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                dfs(i, c, seen, g, compSize);
                c++;
            }
        }
        long long ans = 0;
        long long prevSum = 0;
        for (int i = 0; i < n; i++) {
            if (compSize[i] == 0) continue;
            if (prevSum > 0)
                ans += (compSize[i] * prevSum);
            prevSum += compSize[i];
        }
        return ans;
    }
};
