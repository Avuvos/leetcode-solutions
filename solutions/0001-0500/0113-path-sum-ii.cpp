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
    vector<vector<int>> res;

    void dfs(TreeNode* node, vector<int>& current, int sum, int target_sum) {
        if (node == nullptr) return;
        if (node -> left == nullptr && node -> right == nullptr) {
            if (sum + node -> val == target_sum) {
                current.push_back(node -> val);
                res.push_back(current);
                current.pop_back();
                return;
            }
        }
        current.push_back(node -> val);
        dfs(node -> left, current, sum + node -> val, target_sum);
        current.pop_back();
        current.push_back(node -> val);
        dfs(node -> right, current, sum + node -> val, target_sum);
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> current;
        dfs(root, current, 0, targetSum);
        return res;
    }
};
