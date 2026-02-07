class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int x = 0, d = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
            if (nums[i] % 2 == 0) {
                d++;
            } else {
                d--;
            }
            if (mp.contains({x, d})) {
                ans = max(ans, i - mp[{x, d}]);
            } else {
                mp[{x, d}] = i;
            }
        }
        return ans;
    }
};
