class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
       int res = 0, cnt = 0;
        for (int n: nums) {
            res = Math.max(res, cnt);
            if (n == 1) {
                cnt++;
            }
            else {
                cnt = 0;
            }
        }
        return Math.max(res, cnt); 
    }
}
