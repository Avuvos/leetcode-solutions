/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* root = new Node(node -> val);
        unordered_map<int, Node*> seen;
        function<void(Node*, Node*)> dfs = [&](Node* node, Node* new_node) -> void {
            for (auto &nei: node -> neighbors) {
                if (seen.find(nei -> val) == seen.end()) {
                    Node* new_nei = new Node(nei -> val);
                    seen[nei -> val] = new_nei;
                    dfs(nei, new_nei);
                }
                new_node -> neighbors.push_back(seen[nei -> val]);
            }
        };
        seen[node -> val] = root;
        dfs(node, root);
        return root;
    }
};
