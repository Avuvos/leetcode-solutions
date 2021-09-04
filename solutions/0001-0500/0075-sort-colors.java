class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int cntRed = 0;
        int cntWhite = 0;
        int cntBlue = 0;
        
        for (int num: nums) {
            if (num == 0) cntRed++;
            if (num == 1) cntWhite++;
            if (num == 2) cntBlue++;
        }
        
        for (int i=0; i<cntRed; i++) nums[i] = 0;
        for (int i=cntRed; i<cntRed+cntWhite; i++) nums[i] = 1;
        for (int i=cntRed+cntWhite; i<n; i++) nums[i] = 2;
        
    }
}
