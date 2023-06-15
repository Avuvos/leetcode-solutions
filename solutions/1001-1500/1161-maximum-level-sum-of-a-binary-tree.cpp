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
    int maxLevelSum(TreeNode* root) {
        int mx = -1e9, ans = 0, level = 1;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int cur = 0;
            int sz = (int) que.size();
            for (int iter = 0; iter < sz; iter++) {
                TreeNode* node = que.front(); que.pop();
                cur += node -> val;
                if (node -> left != nullptr) que.push(node -> left);
                if (node -> right != nullptr) que.push(node -> right);
            }
            if (cur > mx) {
                mx = cur;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
