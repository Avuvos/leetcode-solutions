class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length, a = 0, b = n - 1;
        int [] res = new int [n];
        for (int i=n-1; i>=0; i--) {
            if (Math.abs(nums[a]) > Math.abs(nums[b])) 
                res[i] = nums[a]*nums[a++];
            else 
                res[i] = nums[b]*nums[b--];
        }
        return res;
    }
}
