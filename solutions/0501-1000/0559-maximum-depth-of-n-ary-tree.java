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
    public int maxDepth(Node root) {
        if (root == null) return 0;
        
        int depth = 0;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        
        while(!q.isEmpty()) { //classic BFS
            int size = q.size(); //while we have children
            for (int i=0; i<size; i++) {  
                Node curr = q.poll();     //pull them out of the q
                for (Node child: curr.children) {
                    q.offer(child); //add their children to the q
                }  
            }
            depth++; //increment the depth by 1
        }
        return depth;
        
    }
}
