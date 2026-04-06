class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        // min removals == max subseq that xor equals target
        // it feels like a knapsack problem
        // using only elements 1 to i
        // whats the longest subseq xor we can create for each i from 1 to max_value
        int n = nums.size(), max_value = (1 << 14) - 1;
        vector<int> dp(max_value + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;
            for (int j = 0; j <= max_value; j++) {
                int v = j ^ nums[i];
                if (dp[v] != -1) {
                    ndp[j] = max(ndp[j], 1 + dp[v]);
                }
            }
            swap(dp, ndp);
        }
        if (dp[target] != -1) {
            return n - dp[target];
        }
        return -1;
    }
};
