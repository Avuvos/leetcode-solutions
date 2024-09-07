/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        map<ListNode*, int> lst_id;
        map<TreeNode*, int> tree_id;
        ListNode* current = head;
        int index = 0;
        while (current != nullptr) {
            lst_id[current] = index;
            index++;
            current = current -> next;
        }
        int tot_lst = index + 2;
        index = 0;
        auto traverse = [&](auto &traverse, TreeNode* root) -> void {
            if (root == nullptr) return;
            tree_id[root] = index++;
            traverse(traverse, root -> left);
            traverse(traverse, root -> right);
        };
        traverse(traverse, root);
        int tot_tree = index + 2;
        
        vector<vector<int>> dp(tot_lst, vector<int>(tot_tree, -1));
        
        auto dfs = [&](auto &dfs, ListNode* cur, TreeNode* root) -> bool {
            if (cur == nullptr) {
                return true;
            }
            if (root == nullptr) {
                return false;
            }
            int i = lst_id[cur];
            int j = tree_id[root];
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            bool go_left = dfs(dfs, head, root -> left);
            bool go_right = dfs(dfs, head, root -> right);
            bool take_left = false, take_right = false;
            if (cur -> val == root -> val) {
                take_left = dfs(dfs, cur -> next, root -> left);
                take_right = dfs(dfs, cur -> next, root -> right);
            }
            return dp[i][j] = go_left || go_right || take_left || take_right;
            
        };
        
        return dfs(dfs, head, root);
        
    }
};
