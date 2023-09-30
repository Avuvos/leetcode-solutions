class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto &a: nums) mp[a]++;
        int ans = 0;
        for (auto [key, val]: mp) {
            if (val == 1) {
                return -1;
            }
            if (val % 3 == 0) {
                ans += val / 3;
            } else if (val % 3 == 2) {
                ans += (val - 1) / 3 + 1;
            } else  {
                ans += 2 + (val - 4) / 3;  
            }
        }
        return ans;
    }
};
