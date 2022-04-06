class NumArray {
    
    private int[] prefix;
    private int[] nums;
    
    public NumArray(int[] nums) {
        this.nums = nums;
        prefix = new int[nums.length];
        prefix[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefix[i] += prefix[i - 1] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return prefix[right] - prefix[left] + nums[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
