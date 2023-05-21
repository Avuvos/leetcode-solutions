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
    int findTilt(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return 0;
            int leftSum = dfs(node -> left);
            int rightSum = dfs(node -> right);
            ans += abs(rightSum - leftSum);
            return leftSum+rightSum+node->val;
        };
        dfs(root);
        return ans;
    }
};
