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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) 
            return true;
        return Traversal(root.left, root.right);
}
    public boolean Traversal(TreeNode leftNode, TreeNode rightNode) {
        if (leftNode == null && rightNode == null) 
            return true;
        if (leftNode == null || rightNode == null || leftNode.val != rightNode.val) 
            return false;
        
        return Traversal(leftNode.left, rightNode.right) && 
               Traversal(leftNode.right, rightNode.left);
    }
}
