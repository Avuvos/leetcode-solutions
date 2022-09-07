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
    string preorder(TreeNode* node) {
        string result = to_string(node -> val);
        if (node -> left) result += '(' + preorder(node -> left) + ')';
        else if (node -> right) result += "()";
        if (node -> right) result += '(' + preorder(node -> right) + ')';
        return result;
    }

    string tree2str(TreeNode* root) {
        return preorder(root);
    }
};
