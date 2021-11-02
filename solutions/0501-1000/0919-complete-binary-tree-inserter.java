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
class CBTInserter {
        TreeNode root;
        Deque<TreeNode> deq;
        public CBTInserter(TreeNode root) {
            this.root = root;
            this.deq = new ArrayDeque<>();
            init(root);
        }
        public void init(TreeNode node) {
            if (node == null) return;
            Queue<TreeNode> q = new LinkedList<>();
            q.offer(node);
            while (!q.isEmpty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode curr = q.poll();
                    if (curr.left == null || curr.right == null) {
                        deq.offer(curr);
                    }
                    if (curr.left != null) q.offer(curr.left);
                    if (curr.right != null) q.offer(curr.right);
                }
            }
        }
        public int insert(int val) {
            TreeNode node = deq.pollFirst();
            TreeNode newNode = new TreeNode(val);
            if (node.left == null) {
                node.left = newNode;
                deq.offerFirst(node);
            }
            else {
                node.right = newNode;
            }
            deq.offerLast(newNode);
            return node.val;
        }
        public TreeNode get_root() {
            return this.root;
        }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(val);
 * TreeNode param_2 = obj.get_root();
 */
