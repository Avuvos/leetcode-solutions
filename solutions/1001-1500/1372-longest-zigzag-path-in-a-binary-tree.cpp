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
    int longestZigZag(TreeNode* root) {
        //answer is = max {skip root & left, skip root & right, root & leftson, root & rightson}
        function<array<int, 4>(TreeNode*)> dfs = [&](TreeNode* root) {
            array<int, 4> ans = {0, 0, 0};
            if (root == nullptr) return ans;
            array<int, 4> left_child = dfs(root -> left);
            array<int, 4> right_child = dfs(root -> right);
            ans[1] = 1 + left_child[2];
            ans[2] = 1 + right_child[1];
            ans[0] = max({left_child[0], right_child[0], ans[1], ans[2]});
            return ans;
        };
        return dfs(root)[0] - 1; //since the last node of the chain is actually not counted
    }
};
