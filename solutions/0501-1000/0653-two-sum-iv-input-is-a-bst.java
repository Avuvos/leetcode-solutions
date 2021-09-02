/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    public boolean findTarget(TreeNode root, int k) {
        return findTarget(root, k, map);
    }
    private boolean findTarget(TreeNode root, int k, Map<Integer, Integer> map) {
        if (root == null) return false; 
        if (map.containsKey(root.val)) return true; 
        map.put(k-root.val, 1);
        return findTarget(root.left, k, map) || findTarget(root.right, k, map);
    }
}
