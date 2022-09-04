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
    map<int, map<int, multiset<int>>> mp;
    void dfs(TreeNode* node, int col, int row) {
        if (node == nullptr) return;
        mp[col][row].insert(node -> val);
        dfs(node->left, col - 1, row + 1);
        dfs(node->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, 0);
        for (auto itx = mp.begin(); itx != mp.end(); itx++) {
            res.push_back(vector<int>());
            for (auto ity = itx -> second.begin(); ity != itx -> second.end(); ity++) {
                res.back().insert(end(res.back()), begin(ity -> second), end(ity -> second));
            }
        }
        return res;
    }
};
