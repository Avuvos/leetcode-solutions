class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = (int) nums.size();
        int best = 0, cnt = 0;
        int ones = count(nums.begin(), nums.end(), 1);
        for (int r = 0, l = 0; r < 2 * n; r++) {
            cnt += (nums[r % n] == 1);
            if (r - l + 1 > ones) {
                cnt -= (nums[l % n] == 1);
                l++;
            }
            if (r - l + 1 == ones) {
                best = max(best, cnt);
            }
        }
        return ones - best;
    }
};
