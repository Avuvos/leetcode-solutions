class Solution {
    public int minDeletion(int[] nums) {
        int n = nums.length;
        int res = 0;
        
        for (int i = 0; i < n - 1; i++) {
            boolean deleteIdx = res % 2 == i % 2;
            if (deleteIdx && nums[i] == nums[i + 1]) {
                res++;
            }
        }
        if ((n - res) % 2 == 1) {
            res++;
        }
        return res;
    }
}
