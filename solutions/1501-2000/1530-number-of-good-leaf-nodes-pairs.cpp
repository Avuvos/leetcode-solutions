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
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, vector<TreeNode*>> g;
        map<TreeNode*, bool> is_leaf;
        auto dfs = [&](auto &dfs, TreeNode* root) -> void {
            if (root == nullptr) return;
            bool leaf = true;
            if (root -> left != nullptr) {
                leaf = false;
                g[root].push_back(root -> left);
                g[root -> left].push_back(root);
                dfs(dfs, root -> left);
            }
            if (root -> right != nullptr) {
                leaf = false;
                g[root].push_back(root -> right);
                g[root -> right].push_back(root);
                dfs(dfs, root -> right);
            }
            is_leaf[root] = leaf;
        };
        dfs(dfs, root);
        int ans = 0;
        for (auto [node, leaf]: is_leaf) {
            if (!leaf) continue;
            queue<TreeNode*> q;
            set<TreeNode*> seen;
            q.push(node);
            seen.insert(node);
            int d = 0;
            while (!q.empty()) {
                int sz = (int) q.size();
                for (int i = 0; i < sz; i++) {
                    TreeNode* cur = q.front(); q.pop();
                    if (is_leaf[cur] && cur != node) {
                        ans++;
                    }
                    for (auto &nei: g[cur]) {
                        if (seen.find(nei) == seen.end()) {
                            seen.insert(nei);
                            q.push(nei);
                        }
                    }
                }
                d++;
                if (d > distance) break;
            }
        }
        return ans / 2;
    }
};
