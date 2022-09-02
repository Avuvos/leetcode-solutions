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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int qsize = queue.size();
            long double level_sum = 0;
            int counter = 0;
            for (int i = 0; i < qsize; i++) {
                TreeNode* node = queue.front(); queue.pop();
                level_sum += node -> val;
                counter++;
                if (node -> left != NULL) queue.push(node -> left);
                if (node -> right != NULL) queue.push(node -> right);
            }
            res.push_back(level_sum / counter);
        }
        return res;
        
    }
};
