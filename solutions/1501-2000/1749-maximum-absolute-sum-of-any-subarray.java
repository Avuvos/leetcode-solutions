class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int n = nums.length;
        int currMax = nums[0], bestMax = nums[0];
        int currMin = nums[0], bestMin = nums[0];
        for (int i = 1; i < n; i++) {
            currMax = Math.max(currMax + nums[i], nums[i]);
            bestMax = Math.max(bestMax, currMax);
            currMin = Math.min(currMin + nums[i], nums[i]);
            bestMin = Math.min(bestMin, currMin);
        }
        return Math.max(bestMax, Math.abs(bestMin));
    }
}
