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
    public int deepestLeavesSum(TreeNode root) {
        int maxLevel = depth(root);
        return dfs(root, 1, maxLevel);
    }
    
    public int depth(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(depth(root.left), depth(root.right));
    }
    
    public int dfs(TreeNode root, int currLevel, int Level) {
        if (root == null) return 0;
        if (currLevel == Level) return root.val;
        return dfs(root.left, currLevel + 1, Level) + 
               dfs(root.right, currLevel + 1, Level);
        
    }
}
