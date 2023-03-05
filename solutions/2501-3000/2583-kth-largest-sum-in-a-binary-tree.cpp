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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levels;
        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node == nullptr) continue;
                sum += node -> val;
                if (node -> left != nullptr) {
                    q.push(node -> left);
                }
                if (node -> right != nullptr) {
                    q.push(node -> right);
                }
            }
            levels.push_back(sum);
        }
        sort(levels.rbegin(), levels.rend());
        if (k > levels.size()) return -1;
        return levels[k - 1];
    }
};
