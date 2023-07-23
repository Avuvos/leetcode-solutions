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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return vector<TreeNode*>{};
        
        vector<vector<TreeNode*>> dp(n + 1);
        
        function<vector<TreeNode*>(int)> dfs = [&](int rem) {
            vector<TreeNode*> ans;
            if (rem == 0) {
                return ans;
            }
            if (rem == 1) {
                TreeNode* root = new TreeNode(0);
                ans.push_back(root);
                return ans;
            }
            
            if (dp[rem].size() > 0) {
                return dp[rem];
            }
            
            for (int i = 1; i < rem; i += 2) {
                vector<TreeNode*> leftTrees = dfs(i);
                vector<TreeNode*> rightTrees = dfs(rem - 1 - i);
                for (auto t1: leftTrees)
                    for (auto t2: rightTrees)
                        ans.push_back(new TreeNode(0, t1, t2));
            }
            dp[rem] = ans;
            return dp[rem];          
            
        };
        return dfs(n);
    }
};
