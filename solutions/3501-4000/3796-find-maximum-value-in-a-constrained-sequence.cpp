class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> dp(n, 1e9 + 2);
        for (auto &r: restrictions) {
            dp[r[0]] = r[1];
        }
        dp[0] = 0;
        for (int i = 0; i + 1 < n; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + diff[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = min(dp[i],  dp[i + 1] + diff[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
