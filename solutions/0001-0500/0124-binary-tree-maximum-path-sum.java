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

//crucial observation, we can only split from ONE node
//so if we dont split we have to choose either left or right, choose the max
//if we do split we just add the result of the left path and the right path
//keep updating the max as we continue the traversal

class Solution {
    int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        dfs(root);
        return maxSum;
    }
    public int dfs(TreeNode root) {
        if (root == null) return 0;
        
        //getting best sum paths from left and right, in case of negative make it 0
        int maxPathLeft = Math.max(dfs(root.left), 0); 
        int maxPathRight = Math.max(dfs(root.right), 0);
    
        int withSplit = root.val + maxPathLeft + maxPathRight;//split from here
        maxSum = Math.max(maxSum, withSplit); //update the global max
        
        return root.val + Math.max(maxPathLeft, maxPathRight);//no split, choose one
    }   
}
