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
    public boolean isEvenOddTree(TreeNode root) {
        int level = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        
        while(!q.isEmpty()) { //classic BFS
            int size = q.size();
            int prevE = Integer.MIN_VALUE; //for the even levels
            int prevO = Integer.MAX_VALUE; //for the odd levels
            for (int i=0; i<size; i++) { 
                TreeNode curr = q.poll(); //check the conditions of the problem
                if (level % 2 == 0) { 
                    if (curr.val <= prevE || curr.val % 2 == 0) 
                        return false;
                    else 
                        prevE = curr.val;
                }
                else {
                    if (curr.val >= prevO || curr.val % 2 == 1) 
                        return false;
                    else 
                        prevO = curr.val;
                }
                if (curr.left != null) q.offer(curr.left); //add the children to the q
                if (curr.right != null) q.offer(curr.right);
            }
            level++; //update the level
        }
        return true; //if we got here everything is good so return true
    }
}
