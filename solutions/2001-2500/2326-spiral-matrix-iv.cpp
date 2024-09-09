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
class Solution {
public:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 && i < m && j >= 0 && j < n && ans[i][j] == -1;
        };
        
        auto get_next_dir = [&](int i, int j, int dir) -> int {
            int ni = i + DIRECTIONS[dir].first;
            int nj = j + DIRECTIONS[dir].second;
            if (!valid(ni, nj)) {
                dir = (dir + 1) % 4;
            }
            return dir;
        };
        
        ListNode* cur = head;
        int i = 0, j = 0, dir = 0;
        while (cur != nullptr) {
            ans[i][j] = cur -> val;
            cur = cur -> next;
            dir = get_next_dir(i, j, dir);
            i += DIRECTIONS[dir].first;
            j += DIRECTIONS[dir].second;
        }
        
        return ans;
    }
};
