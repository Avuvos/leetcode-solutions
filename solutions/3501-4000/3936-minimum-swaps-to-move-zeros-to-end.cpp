class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int z = count(nums.begin(), nums.end(), 0), ans = z;
        for (int i = n - 1; i >= n - z; i--) {
            if (nums[i] == 0) {
                ans--;
            }
        }
        return ans;
    }
};
