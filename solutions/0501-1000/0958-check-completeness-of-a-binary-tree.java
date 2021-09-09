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
    public boolean isCompleteTree(TreeNode root) {
        int depth = depth(root);
        if (depth == 1) 
            return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int lvl = 1;
        boolean end = false;
        while (!q.isEmpty()) {
            int size = q.size();
            int countNodes = 0;
            for (int i=0; i<size; i++) {
                TreeNode curr = q.poll();
                countNodes++;
                if (lvl == depth - 1) {
                    if (end && (curr.left != null || curr.right != null)) {
                        return false;
                    }
                    if (curr.left == null && curr.right != null) {
                        return false;
                    }
                    if (curr.left == null || curr.right == null) {
                        end = true;
                    }
                }
                else {
                    if (curr.left != null) q.offer(curr.left);
                    if (curr.right != null) q.offer(curr.right);
                }
            }
            if (lvl != depth && countNodes != Math.pow(2, lvl-1)) 
                return false;
            lvl++;
        }
        return true;
        
    }
    
    public int depth(TreeNode root) {
        if (root == null) 
            return 0;
        return 1 + Math.max(depth(root.left), depth(root.right));
    }
}
