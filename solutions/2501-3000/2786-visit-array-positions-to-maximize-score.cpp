class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        function<ll(int, int)> dfs = [&](int index, int par) -> ll {
            if (index >= n) return 0;
            if (dp[index][par] != -1) return dp[index][par];
            ll take = 0, skip = 0;
            int mypar = nums[index] % 2;
            take = nums[index] + dfs(index + 1, mypar);
            if (mypar != par) {
                take -= x;
            }
            skip = dfs(index + 1, par);
            dp[index][par] = max(skip, take);
            return dp[index][par];
        };
        return nums[0] + dfs(1, nums[0] % 2);
    }
};
