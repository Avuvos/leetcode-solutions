class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;        
        function<int(int, int)> dfs = [&](int index, int cur) {
            if (cur == 0) 
                return 1;
            if (index >= nums.size() || cur < 0)
                return 0;
            if (dp[cur] != -1)
                return dp[cur];
            return dp[cur] = dfs(index + 1, cur) + dfs(0, cur - nums[index]);
        };
        return dfs(0, target);
    }
};
