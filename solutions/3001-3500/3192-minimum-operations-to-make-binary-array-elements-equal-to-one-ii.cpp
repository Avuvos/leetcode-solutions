class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, f = 0, n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] ^= f;
            if (nums[i] == 0) {
                ans++;
                f ^= 1;
            }
        }
        return ans;
    }
};
