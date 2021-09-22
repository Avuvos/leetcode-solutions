class Solution {
    public int singleNumber(int[] nums) {
        //since XOR is commutative and a^a is always 0
        //everything will cancel out and we will get the number we need
        int res = 0;
        for (int i=0; i<nums.length; i++) {
            res = res^nums[i]; 
        }
        return res;
    }
}
