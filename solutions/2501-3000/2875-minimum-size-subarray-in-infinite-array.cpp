class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = (int) nums.size();
        const int inf = 1e9 + 2;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long rep = target / sum;
        target %= sum;
        long long ans = inf;
        map<long long, int> mp;
        mp[0] = -1;
        long long s = 0;
        for (int i = 0; i < 2*n; i++) {
            mp[s] = i;
            if (mp.find(s - target) != mp.end()) {
                ans = min(ans, i - (long long) mp[s - target]);
            }
            s += nums[i % n];
        }
        
        return ans < inf ? (ans + n * rep) : -1;
    }
};
