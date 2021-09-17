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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root == null) return new ArrayList<>();
        q.offer(root);
        boolean LTR = false; //left to right, changes every level
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> lst = new ArrayList<>();
            for (int i=0; i<size; i++) {
                TreeNode curr = q.poll();
                if (LTR) { //add from the left
                    lst.add(0, curr.val);
                }
                else { //add fomr the right
                    lst.add(curr.val);
                }
                if (curr.left != null) q.offer(curr.left);
                if (curr.right != null) q.offer(curr.right);
            }
            LTR = !LTR; //swap sides
            res.add(lst);
        }
        return res;
    }
    
}
