class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && nums[i] == nums[i + 1]) {                
                i++;
                cnt++;
            }
            for (int j = 0; j < min(cnt, k); j++) {
                ans.push_back(nums[i]);
            }
            i++;
        }
        return ans;
    }
};
