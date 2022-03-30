/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> lst = new ArrayList<Integer>();
        if (root == null) return lst;
        
        Stack<Node> stack = new Stack<Node>();
        Node curr = root; //just to not modify the root
        stack.push(curr);
        
        while (!stack.isEmpty()) {
            lst.add(curr.val);
            for (int i=curr.children.size()-1; i >=0; i--) {
                stack.push(curr.children.get(i));
            }
            curr = stack.pop();
        }
        return lst;
    }
}
