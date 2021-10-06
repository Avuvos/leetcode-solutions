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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        int lvl = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (lvl == depth - 1) {
                    TreeNode prevLeft = node.left, prevRight = node.right;
                    node.left = new TreeNode(val);
                    node.right = new TreeNode(val);
                    node.left.left = prevLeft;
                    node.right.right = prevRight;
                }
                else {
                    if (node.left != null) q.offer(node.left);
                    if (node.right != null) q.offer(node.right);
                }
            }
            if (lvl == depth - 1) {
                return root;
            }
            lvl++;
        }
        return root;
    }
}
