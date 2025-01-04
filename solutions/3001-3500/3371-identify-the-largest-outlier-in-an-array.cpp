class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size(), ans = -1e9;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        multiset<int> ms(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            ms.erase(ms.find(nums[i]));
            int cur_sum = sum - nums[i];
            if (cur_sum % 2 == 0 && ms.contains(cur_sum / 2)) {
                ans = max(ans, nums[i]);
            }
            ms.insert(nums[i]);
        }
        return ans;

    }
};
