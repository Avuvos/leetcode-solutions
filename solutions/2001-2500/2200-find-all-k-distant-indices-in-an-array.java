class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> res = new ArrayList<>();
        int pos = 0, n = nums.length;
        for (int i = 0; i < n; i++) {
            while (pos < n && (nums[pos] != key || pos < i - k)) pos++;
            if (pos == n) break;
            if (i - k <= pos && pos <= i + k) res.add(i);
        }
        return res;
    }
}
