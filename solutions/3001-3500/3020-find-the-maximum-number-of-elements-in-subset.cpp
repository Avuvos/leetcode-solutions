class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> mp;
        for (auto &x: nums) mp[x]++;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            if (x == 1) {
                ans = max(ans, mp[x] - !(mp[x] & 1));
                continue;
            }
            int cur = 0; 
            while (x < 1e10 && mp[x] >= 2) {
                x *= x;
                cur += 2;
            }
            if (mp[x] >= 1) {
                cur++;
            } else {
                cur--;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
