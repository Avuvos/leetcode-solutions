class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int cur = nums[0];
        for (auto &x: nums) {
            while (cur < x) {
                ans.push_back(cur);
                cur++;
            }
            cur = x + 1;
        }
        return ans;
    }
};
