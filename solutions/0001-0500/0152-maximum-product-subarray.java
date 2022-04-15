class Solution {
    public int maxProduct(int[] nums) {
        int maxP = nums[0];
        int currMax = 1;
        int currMin = 1;
        
        for (int num: nums) {
            int tmp = currMax * num;
            currMax = Math.max(Math.max(tmp, currMin*num), num);
            currMin = Math.min(Math.min(tmp, currMin*num), num);
            
            if (currMax > maxP)
                maxP = currMax;
        }
        
        return maxP;
    }
}
