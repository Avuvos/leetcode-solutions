class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        generateSubsets(nums, 0, new ArrayList<>(), res);
        return res;
    }
    public void generateSubsets(int[] nums, int i,List<Integer> path,List<List<Integer>> res) {
        if (i >= nums.length) {
            res.add(new ArrayList(path));
            return;
        }
        path.add(nums[i]);
        generateSubsets(nums, i + 1, path, res);
        path.remove(path.size() - 1);
        generateSubsets(nums, i + 1, path, res);
    }
}
