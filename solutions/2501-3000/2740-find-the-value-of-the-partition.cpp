class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1e9 + 17;
        for (int i = 0; i + 1 < nums.size(); i++) {
            ans = min(ans, abs(nums[i + 1] - nums[i]));
        }
        return ans;
    }
};
