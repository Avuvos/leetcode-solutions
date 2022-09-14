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
    int dfs(TreeNode* node, vector<int>& mask) {
        if (!node) return 0;
        int good_path = 0;

        if (mask[node -> val] == 1) mask[node -> val] = 0;
        else mask[node -> val] = 1;

        if (!node -> left && !node -> right) {
            good_path = std::count(mask.begin(), mask.end(), 1) <= 1;
        }
        int left = dfs(node -> left, mask);
        int right = dfs(node -> right, mask);

        if (mask[node -> val] == 0) mask[node -> val] = 1;
        else mask[node -> val] = 0;

        return good_path + left + right;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mask(10, 0);
        return dfs(root, mask);
    }
};
