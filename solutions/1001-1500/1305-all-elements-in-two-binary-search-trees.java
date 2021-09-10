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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> lst1 = inorder(root1, new ArrayList<>());
        List<Integer> lst2 = inorder(root2, new ArrayList<>());
        return merge(lst1, lst2);
    }
    
    public List<Integer> inorder(TreeNode root, List<Integer> lst) {
        if (root == null) return lst;
        inorder(root.left, lst);
        lst.add(root.val);
        inorder(root.right, lst);
        return lst;
    }
    
    public List<Integer> merge(List<Integer> lst1, List<Integer> lst2) {
        List<Integer> res = new ArrayList<>();
        int a = 0;
        int b = 0;
        while (a < lst1.size() && b < lst2.size()) {
            if (lst1.get(a) < lst2.get(b)) {
                res.add(lst1.get(a));
                a++;
            }
            else {
                res.add(lst2.get(b));
                b++;
            }
        }
        while (a < lst1.size()) {
            res.add(lst1.get(a));
            a++;
        }
        while (b < lst2.size()) {
            res.add(lst2.get(b));
            b++;
        }
        return res;      
    }
}
