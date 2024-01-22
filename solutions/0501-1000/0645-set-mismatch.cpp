class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            ans[1] ^= (i+1);
            ans[1] ^= nums[i];
            if (seen.find(nums[i]) != seen.end()) {
                ans[0] = nums[i];
                ans[1] ^= nums[i];
            }
            seen.insert(nums[i]);
        }
        return ans;
    }
};
