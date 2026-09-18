class Solution {
public:
    const int INF = 1e9 + 2;
    int dp[101][5001];
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        int mx_sum = max(sum, *max_element(nums.begin(), nums.end()));
        vector<vector<int>> dist(n, vector<int>(mx_sum + 1, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= mx_sum; j++) {
                dist[i][j] = (nums[i] == j) ? 0 : INF;
            }
        }
        vector<vector<int>> cands(n);
        for (int st = 0; st < n; st++) {
            queue<int> q;
            q.push(nums[st]);
            cands[st].push_back(nums[st]);
            while (!q.empty()) {
                int x = q.front(); q.pop();
                int y = 2 * x;
                if (y <= sum && dist[st][y] == INF) {
                    dist[st][y] = dist[st][x] + 1;
                    cands[st].push_back(y);
                    q.push(y);
                }
                y = x / 2;
                if (y >= 1 && dist[st][y] == INF) {
                    dist[st][y] = dist[st][x] + 1;
                    cands[st].push_back(y);
                    q.push(y);
                }
            }
            sort(cands[st].begin(), cands[st].end());
        }
        auto dfs = [&](auto &dfs, int i, int s) -> int {
            if (s == sum) {
                return 0;
            }
            if (i >= n || s > sum) {
                return INF;
            }
            if (dp[i][s] != -1) {
                return dp[i][s];
            }
            int best = dfs(dfs, i + 1, s);
            for (auto &c: cands[i]) {
                if (s + c > sum) break; // cands[i] is sorted!
                best = min(best, dist[i][c] + dfs(dfs, i + 1, s + c));
            }
            return dp[i][s] = best;
        };
        memset(dp, -1, sizeof(dp));
        int ans = dfs(dfs, 0, 0);
        return ans < INF ? ans : -1;
    }
};

