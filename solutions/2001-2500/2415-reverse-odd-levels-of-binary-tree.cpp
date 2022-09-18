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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> current_level;
            vector<int> next_level;
            for (int iter = 0; iter < size; ++iter) {
                TreeNode* node = q.front(); q.pop();
                current_level.push_back(node);
                if (node -> left != nullptr) {
                    q.push(node -> left);
                    next_level.push_back(node -> left -> val);
                }
                if (node -> right != nullptr) {
                    q.push(node -> right);
                    next_level.push_back(node -> right -> val);
                }
            }
            reverse(next_level.begin(), next_level.end());

            if (level % 2 == 0) {
                int ptr = 0;
                for (auto &node: current_level) {
                    if (ptr < next_level.size()) {
                        node -> left -> val = next_level[ptr];
                        ptr++;
                    }
                    if (ptr < next_level.size()) {
                        node -> right -> val = next_level[ptr];
                        ptr++;
                    }
                }
            }
            current_level.clear();
            next_level.clear();
            level++;
        }
        return root;
    }

};
