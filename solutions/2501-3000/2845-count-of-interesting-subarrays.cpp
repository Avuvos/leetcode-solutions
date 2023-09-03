class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp = {{0, 1}};
        for (auto num: nums) {
            sum = (sum + (num % mod == k)) % mod;
            ans += mp[(sum - k + mod) % mod];
            mp[sum]++;
        }
        return ans;
    }
};

