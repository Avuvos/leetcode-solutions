class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto &x: nums) mp[x]++;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            bool bad = false;
            for (auto &[_, v]: mp) {
                if (v > 1) {
                    bad = true;
                }
            }
            if (!bad) break;
            mp[nums[i]]--;
            ans++;
            if (i + 1 < n) {
                mp[nums[i + 1]]--;
            }
            if (i + 2 < n) {
                mp[nums[i + 2]]--;
            }
        }
        return ans;
    }
};
