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
const int MOD = 1e9 + 7;
long long s = 0;
long long res = 0;
class Solution {
public:
    long long sumTree(TreeNode* root) {
        if (root == NULL) return 0;
        return root -> val + sumTree(root -> left) + sumTree(root -> right);
    }
    
    long long traverse(TreeNode* root) {
        if (root == NULL) return 0;
        long long subtree_sum = root-> val + traverse(root -> left) + traverse(root -> right);
        res = max(res, subtree_sum * (s - subtree_sum));
        return subtree_sum;
    }
    
    int maxProduct(TreeNode* root) {
        s = sumTree(root);
        res = 0;
        traverse(root);
        return res % MOD;
    }
};
