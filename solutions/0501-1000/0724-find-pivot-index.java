class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int[] preSum = new int[n + 1];
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            int leftSum = i == 0 ? 0 : preSum[i - 1];
            int rightSum = i == n - 1 ? 0 : preSum[n - 1] - preSum[i];
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
}
