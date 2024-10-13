class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                ans[i] = nums[i] - 1;
                int x = nums[i], best = nums[i], k = -1;
                while (x % 2 == 1) {
                    k++;
                    x >>= 1;
                }
                if (k >= 0) {
                    best ^= (1 << k);
                }
                ans[i] = best;
            }
        }
        return ans;
    }
};
