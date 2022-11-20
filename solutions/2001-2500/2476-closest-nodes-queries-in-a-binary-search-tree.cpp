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
    vector<int> nums;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        nums.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < queries.size(); i++) {
            int target = queries[i];
            vector<int> curr(2, -1);
            auto it = lower_bound(nums.begin(), nums.end(), target);
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int m = left + (right - left)/2;
                if (nums[m] == target) {
                    curr[0] = target;
                    curr[1] = target;
                    break;
                } else if (nums[m] > target) {
                    curr[1] = nums[m];
                    right = m - 1;
                } else {
                    curr[0] = nums[m];
                    left = m + 1;
                }
                
                
            }
            res.push_back(curr);
        }
        return res;
    }
};
