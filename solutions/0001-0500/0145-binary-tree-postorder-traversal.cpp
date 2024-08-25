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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](auto &dfs, TreeNode* node) -> void {
            if (!node) return;
            dfs(dfs, node -> left);
            dfs(dfs, node -> right);
            ans.push_back(node -> val);
        };
        dfs(dfs, root);
        return ans;
    }
};
