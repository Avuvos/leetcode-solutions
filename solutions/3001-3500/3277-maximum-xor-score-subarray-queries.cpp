class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        
        //score[i][j] is the xor-score of the subarray nums[i...j]
        vector<vector<int>> score(n, vector<int>(n)); 
        
        //dp[i][j] is the answer for the subarray[i..j]
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            score[i][i] = nums[i];
            dp[i][i] = nums[i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                score[i][j] = score[i + 1][j] ^ score[i][j - 1];
                dp[i][j] = max({score[i][j], dp[i + 1][j], dp[i][j - 1]});
            }
        }
        
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = dp[l][r];
        }
        return ans;
    }
};
