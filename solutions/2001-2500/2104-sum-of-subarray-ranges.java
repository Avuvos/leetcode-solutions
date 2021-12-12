class Solution {
    public long subArrayRanges(int[] nums) {
        int N = nums.length;
        long res = 0;
        int[][] dpMax = new int[N][N];
        int[][] dpMin = new int[N][N];
        for (int i = 0; i < N; i++) {
            dpMax[i][i] = nums[i];
            dpMin[i][i] = nums[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                dpMax[i][j] = Math.max(dpMax[i][j - 1], nums[j]);
                dpMin[i][j] = Math.min(dpMin[i][j - 1], nums[j]);
                res += (dpMax[i][j] - dpMin[i][j]);
            }
        }
        return res; 
    }
}
