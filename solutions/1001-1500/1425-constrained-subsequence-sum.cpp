class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        multiset<int> ms;
        int n = (int) nums.size();
        vector<int> dp(n);
        for (int i = 0, j = 0; i < n; i++) {
            if (i - j > k) {
                ms.erase(ms.find(dp[j++]));
            }
            dp[i] = nums[i] + (!ms.empty() ? max(*ms.rbegin(), 0) : 0);
            ms.insert(dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
