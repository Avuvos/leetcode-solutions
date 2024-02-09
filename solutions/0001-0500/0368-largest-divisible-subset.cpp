class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    
        while (idx != -1) {
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ans;
    }
};
