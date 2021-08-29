class Solution {
    public int minPatches(int[] nums, int n) {
     long miss = 1;
     int i = 0;
     int added = 0;
    
     while (miss <= n) { //miss is the smallest sum we are missing in the range [1, n]
         if (i < nums.length && nums[i] <= miss) {
             miss += nums[i]; //if there's a number less than the missing sum, add it to the sum
             i += 1;          //and increase the range to [1, miss + num]
         }
         else {
             added += 1; //if there isnt, then we need to patch a number, and we patch miss to maximize the values we can get
             miss = miss * 2;
         }
     }
     return added;
    }
}
