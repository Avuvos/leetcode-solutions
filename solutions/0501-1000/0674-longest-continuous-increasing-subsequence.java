class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int res = 1, i = 1, cnt = 1, prev = nums[0];
        while (i < nums.length) {
            if (nums[i] > prev) {
                cnt++;
            }
            else {
                res = Math.max(res, cnt);
                cnt = 1;
            }
            prev = nums[i];
            i++;
        }
        res = Math.max(res, cnt);
        return res;
    }
}
