class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto &x: nums) {
            mp[x]++;
        }
        int ans = 0;
        for (auto [key, val]: mp) {
            if (val % k == 0) {
                ans += val * key;
            }
        }
        return ans;
    }
};
