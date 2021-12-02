class Solution {
    public int minimumDeletions(int[] nums) {
        int N = nums.length;
        int minIdx = 0, minVal = nums[0];
        int maxIdx = 0, maxVal = nums[0];
        for (int i = 1; i < N; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }
        }
        int front = Math.max(minIdx, maxIdx) + 1;
        int back = N - Math.min(minIdx, maxIdx);
        int mid = Math.min(minIdx, maxIdx) + (N - Math.max(minIdx, maxIdx)) + 1;
        
        return Math.min(Math.min(front, back), mid);
        
        
        
    }
}
