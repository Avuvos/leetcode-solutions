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
    public TreeNode createBinaryTree(int[][] descriptions) {
        //edge from parent -> child
        //list of the parent neigh is the left and right child basically
        Map<Integer, List<int[]>> tree = new HashMap<>();
        Set<Integer> notRootSet = new HashSet<>();
        for (int[] node: descriptions) {
            tree.putIfAbsent(node[0], new ArrayList<>());
            tree.get(node[0]).add(new int[]{node[1], node[2]});
            notRootSet.add(node[1]);
        }
        TreeNode root = findRoot(descriptions, notRootSet);
        dfs(root, tree);
        return root;
    }

    private TreeNode findRoot(int[][] descriptions ,Set<Integer> notRoot) {
        for (int[] node: descriptions) {
            if (!notRoot.contains(node[0])) {
                return new TreeNode(node[0]);
            }
        }
        return null;
    }

    private void dfs(TreeNode node, Map<Integer, List<int[]>> tree) {
        for (int[] child: tree.getOrDefault(node.val, new ArrayList<>())) {
            if (child[1] == 1) {
                node.left = new TreeNode(child[0]);
                dfs(node.left, tree);
            }
            else {
                node.right = new TreeNode(child[0]);
                dfs(node.right, tree);
            }
        }
    }
}
