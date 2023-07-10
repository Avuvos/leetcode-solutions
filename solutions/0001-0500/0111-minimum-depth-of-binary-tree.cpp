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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        int ans = 1e5;
        if (root -> left != nullptr) {
            ans = min(ans, 1 + minDepth(root -> left));
        }
        if (root -> right != nullptr) {
            ans = min(ans, 1 + minDepth(root -> right));
        }
        return ans;
    }
};
