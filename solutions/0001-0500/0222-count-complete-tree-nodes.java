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
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        int leftH = 0, rightH = 0;
        TreeNode leftNode = root, rightNode = root;
        while (leftNode != null) {
            leftH++;
            leftNode = leftNode.left;
        }
        while (rightNode != null) {
            rightH++;
            rightNode = rightNode.right;
        }
        if (rightH == leftH) {
            return (int) (Math.pow(2, leftH) - 1);
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
