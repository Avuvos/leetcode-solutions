class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size() + 1, vector<int>(cuts.size() + 1, -1));
        function<int(int, int)> dfs = [&](int left, int right) {
            if (right - left <= 1) return 0;
            if (dp[left][right] != -1) return dp[left][right];
            int ans = 1e9, current;
            for (int index = left + 1; index < right; index++) {
                current = cuts[right] - cuts[left] + dfs(left, index) + dfs(index, right);
                ans = min(ans, current);
            }
            dp[left][right] = ans;
            return ans;
        };
        return dfs(0, cuts.size() - 1);
    }
};
