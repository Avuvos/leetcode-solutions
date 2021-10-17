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
    //notice that the result is the amount of valid paths from root + dfsleft and dfsright
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;
        return dfs(root, targetSum) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }
    public int dfs(TreeNode root, int target) { //rootdfs -> valid paths from the root
        int res = 0;
        if (root == null) return res;
        if (target == root.val) res++;
        int resLeft = dfs(root.left, target - root.val);
        int resRight = dfs(root.right, target - root.val);
        res += resLeft += resRight;
        return res;
    }
}
