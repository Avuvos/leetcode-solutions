/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* cur, TreeNode* par) {
            if (cur == nullptr) return;
            parent[cur] = par;
            dfs(cur -> left, cur);
            dfs(cur -> right, cur);
        };
        dfs(root, nullptr);
        queue<TreeNode*> q;
        q.push(target);
        set<int> seen;
        seen.insert(target -> val);
        vector<int> ans;
        int dist = 0;
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int iter = 0; iter < sz; iter++) {
                TreeNode* cur = q.front(); q.pop();
                if (dist == k) ans.push_back(cur -> val);
                if (cur -> left != nullptr && !seen.count(cur->left->val)) {
                    seen.insert(cur -> val);
                    q.push(cur -> left);
                }
                if (cur -> right != nullptr && !seen.count(cur->right->val)) {
                    seen.insert(cur -> val);
                    q.push(cur -> right);
                }
                if (parent[cur] != nullptr && !seen.count(parent[cur]->val)) {
                    seen.insert(parent[cur] -> val);
                    q.push(parent[cur]);
                }
            }
            dist++;
        }
        return ans;
    }
};
