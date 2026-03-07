class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto &x: nums) {
            mp[x]++;
        }
        vector<int> ans = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mp[nums[i]] == mp[nums[j]]) continue;
                if (ans[0] == -1 || nums[i] < ans[0] || (nums[i] == ans[0] && nums[j] < ans[1])) {
                    ans = {nums[i], nums[j]};
                } else if (nums[j] < ans[0] || (nums[j] == ans[0] && nums[i] < ans[1])) {
                    ans = {nums[j], nums[i]};
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
