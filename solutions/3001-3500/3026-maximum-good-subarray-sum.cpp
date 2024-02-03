class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = (int) nums.size();
        const long long INF = 1e18;
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        } 
        map<int, int> mp;
        long long ans = -INF;
        for (int i = 0; i < n; i++) {
            int x = nums[i] - k;
            if (mp.find(x) != mp.end()) {
                ans = max(ans, ps[i + 1] - ps[mp[x]]);
            }
            x = nums[i] + k;
            if (mp.find(x) != mp.end()) {
                ans = max(ans, ps[i + 1] - ps[mp[x]]);
            }
            
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                int p = mp[nums[i]];
                if (ps[i + 1] - ps[p + 1] < 0) {
                    mp[nums[i]] = i;
                }
            }
        }
        return ans > -INF ? ans : 0;
    }
};
