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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<pair<int, int>> current;
            unordered_map<int, int> num_to_idx;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                current.push_back({node -> val, i});
                num_to_idx[node -> val] = i;
                if (node -> left != NULL) q.push(node -> left);
                if (node -> right != NULL) q.push(node -> right);
            }
            vector<pair<int, int>> tmp(current.begin(), current.end());
            sort(current.begin(), current.end());
            int t = 0, s = 0;
            while (t < tmp.size()) {
                if (tmp[t].first == current[s].first) {
                    s++;
                    t++;
                } else {
                    int index = num_to_idx[current[s].first];
                    num_to_idx[current[s].first] = t;
                    num_to_idx[tmp[t].first] = index;
                    swap(tmp[t], tmp[index]);
                    
                    res++;
                    t++;
                    s++;
                    //cout << " after " << tmp[t].first << " " << tmp[index].first << "\n";
                    
                }
            }
        }
        return res;
    }
};
