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
    int maxLen = 0;
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        dfs(root);
        return maxLen;
        
    }
    public int dfs(TreeNode root) {
        if (root == null) return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        int currL = 0;
        int currR = 0;
        if (root.left != null && root.left.val == root.val) {
            currL += left + 1;
        }
        if (root.right != null && root.right.val == root.val) {
            currR += right + 1;
        }
        maxLen = Math.max(maxLen, currL + currR);
        return Math.max(currL, currR);
         
        
    }
}
