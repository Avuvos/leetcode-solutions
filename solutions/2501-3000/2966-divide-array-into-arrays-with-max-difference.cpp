class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<vector<int>> ans(n / 3);
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < n; i += 3, j++) {
            if (nums[i + 2] - nums[i] > k) {
                return vector<vector<int>>{};
            }
            ans[j] = {nums[i], nums[i + 1], nums[i + 2]};
        }
        return ans;
        
    }
};
