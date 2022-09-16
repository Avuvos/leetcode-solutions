typedef long long ll;
class Solution {
public:
    ll dfs(int left, int right, vector<int>& nums, vector<int>& multipliers, vector<vector<ll>>& dp) {
        int index = left + (nums.size() - right - 1);
        int fixed_right = multipliers.size() - (nums.size() - right - 1);
        if (index >= multipliers.size()) return 0;
        if (dp[left][fixed_right] != INT_MIN) return dp[left][fixed_right];
        ll take_left = multipliers[index] * nums[left] + dfs(left + 1, right, nums, multipliers, dp);
        ll take_right = multipliers[index] * nums[right] + dfs(left, right - 1, nums, multipliers, dp);
        dp[left][fixed_right] = max(take_left, take_right);
        return dp[left][fixed_right];
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<ll>> dp(m + 1, vector<ll>(m + 1, INT_MIN));
        return dfs(0, n - 1, nums, multipliers, dp);
    }
};
