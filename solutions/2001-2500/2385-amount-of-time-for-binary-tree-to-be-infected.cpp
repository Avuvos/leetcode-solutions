/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* parents[100005];
    bool seen[100005] = {};
    void par(TreeNode* parent, TreeNode* node) {
        if (node == NULL) return;
        parents[node -> val] = parent;
        par(node, node -> left);
        par(node, node -> right);
    }
    int amountOfTime(TreeNode* root, int start) {
        parents[root -> val] = NULL;
        par(root, root -> left);
        par(root, root -> right);
        TreeNode* start_parent = parents[start];
        TreeNode* s;
        if (start_parent == NULL) s = root;
        else if (start_parent -> left != NULL && start_parent -> left -> val == start) {
            s = start_parent -> left;
        }
        else s = start_parent -> right;

        queue<TreeNode*> q;
        q.push(s);
        int steps = 0;
        while (q.size() > 0){
            bool ch = false;
            long long size = q.size();
            for (long long i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node == NULL) continue;
                if (seen[node -> val]) continue;
                ch = true;
                seen[node -> val] = true;
                if (parents[node -> val] != NULL) q.push(parents[node -> val]);
                if (node -> left != NULL) q.push(node -> left);
                if (node -> right != NULL) q.push(node -> right);
            }
            if (!ch) break;
            steps++;
        }
        return max(0, steps - 1);
    }
};
