class Solution {
    public int mostFrequent(int[] nums, int key) {
        Set<Integer> keys = new HashSet<>();
        for (int num: nums) {
            keys.add(num);
        }
        int res = 0;
        int best = 0;
        for (int target: keys) {
            int curr = 0;
            for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] == key && nums[i + 1] == target) {
                    curr++;
                }
            }
            if (curr > res) {
                res = curr;
                best = target;
            }
        }
        return best;
    }
}
