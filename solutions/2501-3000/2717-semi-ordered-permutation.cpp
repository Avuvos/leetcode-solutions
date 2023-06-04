class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = (int) nums.size(), ans = 0;
        int seenN = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == n) {
                seenN = true;
                ans += n - i - 1;
            }
            if (nums[i] == 1) {
                ans += i;
                if (seenN) ans--;
            }
        }
        return ans;
    }
};
