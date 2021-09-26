class Solution {
    public int maximumDifference(int[] nums) {
        int best = -1;
        int currMin = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (nums[i] > currMin) {
                best = Math.max(best, nums[i] - currMin);
            }
            else {
                currMin = nums[i];
            }
        }
        return best;
    }
}
