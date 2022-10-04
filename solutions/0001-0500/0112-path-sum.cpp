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
    bool dfs(TreeNode* node, int sum, int targetSum) {
        if (node == nullptr) {
            return false;
        }
        if (node -> left == nullptr && node -> right == nullptr
           && sum + node -> val == targetSum) {
            return true;
        }
        return dfs(node -> left, sum + node -> val, targetSum)
            || dfs(node -> right, sum + node -> val, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
