/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root){
            if (root == null) return "";
            Queue<TreeNode> q = new LinkedList<>();
            String res = "";
            q.offer(root);
            while (!q.isEmpty()) {
                int size = q.size();
                for (int i=0; i<size; i++) {
                    TreeNode curr = q.poll();
                    if (curr == null) {
                        res += "n,";
                        continue;
                    }
                    else {
                        res += String.valueOf(curr.val);
                        res += ",";
                        q.offer(curr.left);
                        q.offer(curr.right);
                    }
                }
            }
            return res;
        }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
            if (data.length() == 0) return null;
            Queue<TreeNode> q = new LinkedList<>();
            String[] values = data.split(",");
            TreeNode root = new TreeNode(Integer.parseInt(values[0]));
            q.offer(root);
            for (int i=1; i<values.length; i++) {
                TreeNode curr = q.poll();
                if (!values[i].equals("n")) {
                    TreeNode leftChild = new TreeNode(Integer.parseInt(values[i]));
                    curr.left = leftChild;
                    q.offer(leftChild);
                }
                i++;
                if (!values[i].equals("n")) {
                    TreeNode rightChild = new TreeNode(Integer.parseInt(values[i]));
                    curr.right = rightChild;
                    q.offer(rightChild);
                }
            }
            return root;
        }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
