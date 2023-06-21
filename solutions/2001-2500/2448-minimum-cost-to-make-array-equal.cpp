class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = (int) nums.size();
        vector<pair<int, int>> both(n);
        for (int i = 0; i < n; i++) {
            both[i] = make_pair(nums[i], cost[i]);
        }
        sort(both.begin(), both.end());
        vector<long long> ps(n + 1, 0);
        vector<long long> sf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + both[i].second;
        }
        for (int i = n - 1; i >= 0; i--) {
            sf[i] = sf[i + 1] + both[i].second;
        }
        vector<long long> dp1(n + 1, 0);
        vector<long long> dp2(n + 1, 0);
        
        for (int i = 1; i < n; i++) {
            dp1[i] = dp1[i - 1] + (both[i].first - both[i - 1].first) * ps[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            dp2[i] = dp2[i + 1] + (both[i + 1].first - both[i].first) * sf[i + 1];
        } 
        long long ans = 1e16;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};
