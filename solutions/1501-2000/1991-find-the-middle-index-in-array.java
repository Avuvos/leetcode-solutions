class Solution {
    public int findMiddleIndex(int[] nums) {
        
        for (int i=0; i<nums.length; i++) {
            int index = i;
            int sum1 = 0;
            int sum2 = 0;
            for (int j=0; j<nums.length; j++) {
                if (j < index) {
                    sum1 += nums[j];
                }   
                else if (j > index) {
                    sum2 += nums[j];
                }
            }
            if (sum1 == sum2) {
                return index;
            }
        }
        return -1;
    }
}
