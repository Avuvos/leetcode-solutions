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
    typedef long long ll;
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<ll> sum_levels;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            ll cur = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                cur += node -> val;
                if (node -> left != nullptr) {
                    q.push(node -> left);
                }
                if (node -> right != nullptr) {
                    q.push(node -> right);
                }
            }
            sum_levels.push_back(cur);
        }
        q.push(root);
        root -> val = 0;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (level + 1 >= sum_levels.size()) continue;
                ll cousins = sum_levels[level + 1];
                if (node -> left != nullptr) {
                    cousins -= node -> left -> val;
                    q.push(node -> left);
                }
                if (node -> right != nullptr) {
                    cousins -= node -> right -> val;
                    q.push(node -> right);
                }
                if (node -> left != nullptr) node -> left -> val = cousins;
                if (node -> right != nullptr) node -> right -> val = cousins;
            }
            level++;
        }
        return root;
    }
};
