class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int a = nums[i], mn = nums[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
                a = a & nums[j];
                if (a == mn) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
