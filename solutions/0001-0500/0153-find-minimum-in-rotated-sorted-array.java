class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) return nums[0];
        
        int left = 0;
        int right = nums.length-1;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            //if the current array is sorted the just return left
            if (nums[mid] > nums[left] && nums[mid] < nums[right]) {
                return nums[left];
            }
            //if we are bigger than right it means the minimum must be on the right
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            //if we got here it means we are SMALLER than right but then if we are smaller than our previous value it means we must be the minimum
            else if (mid > 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            //means that we are smaller than left so the minimum must be on the left 
            else {
                right = mid - 1;
            }
            
        }
        return nums[left];
    }
}
