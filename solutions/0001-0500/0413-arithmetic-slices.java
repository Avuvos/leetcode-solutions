class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int cnt = 0;
        //we ask is there an arithmetic subarray that starts from i?
        //if there is, we check if the next number is also a part of it? 
        //the jump count increases accordingly, and this solution is O(n) time!
        //figured it out completly on my own so im happy with it :)
        for (int i = 0; i < nums.length-2; i++) {
            int j = i;
            int d = nums[j + 1] - nums[j];
            if (nums[j + 2] - nums[ j + 1] == d) { //found series?
                int jump = 1;
                cnt += jump; //add one cuz we found one series
                j += 3; 
                while (j < nums.length && nums[j] - nums[j - 1] == d) {
                    jump += 1; //jump grows linearly
                    cnt += jump; //add jump to the count 
                    j++;
                } 
                i = j - 2; //start from j-2 to avoid edge cases
            }
        }
        return cnt;
    }
}
