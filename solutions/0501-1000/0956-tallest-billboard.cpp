class Solution {
public:
    int dp[21][10001];
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), inf = 1e9;
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs = [&](int index, int s) -> int {
            if (index >= n) {
                if (s == 0) return 0;
                return -inf;
            }
            if (dp[index][s + 5000] != -1) {
                return dp[index][s + 5000];
            }
            int op1 = rods[index] + dfs(index + 1, s + rods[index]);
            int op2 = dfs(index + 1, s - rods[index]);
            int op3 = dfs(index + 1, s);
            int ans = max({op1, op2, op3});
            dp[index][s + 5000] = ans;
            return ans;
        };
        return dfs(0, 0);
    }
};
