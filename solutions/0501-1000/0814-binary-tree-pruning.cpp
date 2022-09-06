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
    bool dfs(TreeNode* node) {
        if (node == nullptr) return true;
        
        bool remove_self = node -> val != 1;
        bool remove_left = dfs(node -> left);
        bool remove_right = dfs(node -> right);
        
        if (remove_left) node -> left = nullptr;
        if (remove_right) node -> right = nullptr;
        
        return remove_self && remove_left && remove_right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? nullptr : root;
    }
};
