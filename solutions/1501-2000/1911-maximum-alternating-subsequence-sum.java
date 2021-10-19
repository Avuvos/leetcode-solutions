class Solution {
    public long maxAlternatingSum(int[] nums) {
        long[][] memo = new long[nums.length + 1][2];
        return maxAlterDFS(nums, 0, 0, memo);
    }
    public long maxAlterDFS(int[] nums, int i, int curr, long[][] memo) {
        if (i >= nums.length) {
            return 0;
        }
        if (memo[i][curr % 2] != 0) {
            return memo[i][curr % 2];
        }
        long take = 0, skip = 0;
        if (curr % 2 == 0) {
            take = maxAlterDFS(nums, i + 1, curr + 1, memo) + nums[i];
        }
        else {
            take = maxAlterDFS(nums, i + 1, curr + 1, memo) - nums[i];
        }
        skip = maxAlterDFS(nums, i + 1, curr, memo);
        memo[i][curr % 2 ] = Math.max(take, skip);
        return Math.max(take, skip);
    }
}
