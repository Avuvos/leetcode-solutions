class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        /*
        dp[i][d] = max length ending at i with maximum allowed disance of d
        it means for some nums[i], we can only take previous elements in the range [nums[i] - d, nums[i] + d].
        so we have a n * d * d solution, but it's too slow probably? 9e8... but should run fast in practice I think .. ?
        actually how to calculate it exactly? still unclear.
        imagine we have many identical elements in this range [nums[i] - d, nums[i] + d], say x appears many times.
        but we only want to check the x with the maximum dp value, our distance is dx = |d - x|
        so we need the maximum over dp[j][dx] where nums[j] == x.
        I think it's safe to assume that this is simply the largest j index, it cannot be "worse" than the optimal result.
        
        so we also have best[element][distance] = ... as we discuessed before. but still too slow.
        
        
        maybe at position i, we can iterate over every unique element x seen so far (at most 300).
        and calculate its best? so we do d = |nums[i] - x| 
        so now we want to update our state to use that d, and connect with the longest seq who has at most d..
        like do some dp[nums[i]][d] max= 1 + dp[x][d] ...
        after finishing those iteration, iterate over all d, and update the "weaker" values
        so like if the max distance allowed is 3, obviously we can update dp[2] max= dp[3]
        since the values for some d are also valid for the dps below it.
        
        */
        
        int n = nums.size(), m = *max_element(nums.begin(), nums.end()) + 2;
        int ans = 1;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            dp[nums[0]][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            int x = nums[i];
            for (int y = 1; y < m; y++) {
                int d = abs(x - y);
                dp[x][d] = max(dp[x][d], 1 + dp[y][d]);
            }
            ans = max(ans, dp[x][m - 1]);
            for (int d = m - 2; d >= 0; d--) {
                dp[x][d] = max(dp[x][d], dp[x][d + 1]);
                ans = max(ans, dp[x][d]);
            }
        }
        return ans;
        
    }
};
