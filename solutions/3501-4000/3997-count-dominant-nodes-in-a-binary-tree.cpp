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
    int countDominantNodes(TreeNode* root) {

        auto dfs = [&](auto &dfs, TreeNode* cur) -> pair<int, int> {
            if (cur == nullptr) {
                return {-1, 0};
            }
            auto [mx_left, cnt_left] = dfs(dfs, cur -> left);
            auto [mx_right, cnt_right] = dfs(dfs, cur -> right);
            int mx = max({cur -> val, mx_left, mx_right});
            int count = cnt_left + cnt_right + (mx == cur -> val);
            return {mx, count};
        };

        return dfs(dfs, root).second;
    }
};
