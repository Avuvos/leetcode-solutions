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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> a;
        
        //return (size, isperfect)
        auto dfs = [&](auto &dfs, TreeNode* root) -> pair<int ,int> {
            //null is size 0 and perfect
            if (root == nullptr) {
                return {0, 1};
            }
            //leaf is size 1 and perfect
            if (root -> left == nullptr && root -> right == nullptr) {
                a.push_back(1);
                return {1, 1};
            }
            auto [sz_left, pf_left] = dfs(dfs, root -> left);
            auto [sz_right, pf_right] = dfs(dfs, root -> right);
            bool pf = pf_left && pf_right && (sz_left == sz_right);
            int sz = 1 + sz_left + sz_right;
            if (pf) {
                a.push_back(sz);
            }
            return {sz, pf};
        };
        dfs(dfs, root);
        sort(a.rbegin(), a.rend());
        return a.size() >= k ? a[k - 1] : -1;
    }
};
