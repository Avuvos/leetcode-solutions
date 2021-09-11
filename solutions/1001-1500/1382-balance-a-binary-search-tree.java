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
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> lst = inorder(root, new ArrayList<>());
        return build(lst, 0, lst.size()-1);
    }
    
    public List<Integer> inorder(TreeNode root, List<Integer> lst) {
        if (root == null) return lst;
        inorder(root.left, lst);
        lst.add(root.val);
        inorder(root.right, lst);
        return lst;
    }
    
    public TreeNode build(List<Integer> lst, int left, int right) {
        if (left > right || left < 0 || right >= lst.size()) return null;
        int mid = (left + right)/2;
        TreeNode node = new TreeNode(lst.get(mid));
        node.left = build(lst, left, mid-1);
        node.right = build(lst, mid+1, right);
        return node;
    }
    
    
}
