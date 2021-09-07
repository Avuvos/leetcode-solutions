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
    private int result = 0;
    
    public int sumEvenGrandparent(TreeNode root) {
        if (root == null) return 0;
        
        dfs(root, root.left);
        dfs(root, root.right);
        return result;
    }
    
    public void dfs(TreeNode grandParent, TreeNode Parent) {
        if (grandParent == null || Parent == null) return;
        
        if (grandParent.val % 2 == 0) { 
            if (Parent.left != null) result += Parent.left.val;
            if (Parent.right != null) result += Parent.right.val;
        }
        
        grandParent = Parent;
        dfs(grandParent, Parent.left);
        dfs(grandParent, Parent.right);
    }
}
