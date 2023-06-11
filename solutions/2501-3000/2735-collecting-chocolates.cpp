class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, int x) {
        const ll inf = 1e10;
        int n = (int) nums.size();
        vector<ll> dp(n, inf);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            ans += dp[i];
        }
        ll cost = 0;
        for (int i = 1; i <= n; i++) {
            cost += x;
            ll cur = cost;
            for (int j = 0; j < n; j++) {
                int idx = (j + i) % n;
                dp[j] = min(dp[j], (ll)nums[idx]);
                cur += dp[j];
            }
            ans = min(ans, cur);
        }
        
        return ans;
    }
};
