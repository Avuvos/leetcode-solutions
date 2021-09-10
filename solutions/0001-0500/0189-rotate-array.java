class Solution {
    
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.length-1);
    }
    
    public void reverse(int [] lst, int left, int right) {
        while (left < right) {
            int temp = lst[left];
            lst[left] = lst[right];
            lst[right] = temp;
            left += 1;
            right -= 1;
        }
    }
}
