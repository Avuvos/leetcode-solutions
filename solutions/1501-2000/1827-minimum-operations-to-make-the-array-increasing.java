class Solution {
    public int minOperations(int[] nums) {
        int cnt = 0;
        for (int i=0; i<nums.length-1; i++) {
            if (nums[i] >= nums[i+1]) {
                cnt += nums[i] - nums[i+1] + 1;
                nums[i+1] += (nums[i]-nums[i+1] + 1);
            }
        }
        return cnt;
    }
}
