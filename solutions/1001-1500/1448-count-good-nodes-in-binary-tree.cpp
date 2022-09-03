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
    int dfs(TreeNode* root, int max_val) {
        if (root == NULL) return 0;
        int im_good = root -> val >= max_val;
        return im_good + dfs(root -> left, max(max_val, root -> val))
                       + dfs(root -> right, max(max_val, root -> val));
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
