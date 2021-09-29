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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (subRoot == null) return true;
        if (root == null) return false;
        List<TreeNode> lst = new ArrayList<>();
        findRoot(root, subRoot.val, lst);
        for (TreeNode r: lst) {
            boolean check = sameTree(r, subRoot); //check if any root matches
            if (check == true) return true;
        }
        return false;     
    }
    
    public void findRoot(TreeNode root, int val, List<TreeNode> lst) {
        if (root == null) return; //find all the possible roots 
        if (root.val == val) lst.add(root);
        findRoot(root.left, val, lst);
        findRoot(root.right, val, lst);
    }
    
    public boolean sameTree(TreeNode root1, TreeNode root2) { //"same tree" problem
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        if (root1.val != root2.val) return false;
        return sameTree(root1.left, root2.left) && sameTree(root1.right, root2.right);  
    }
}
