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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            n++;
            cur = cur -> next;
        }
        cur = head;
        int d = n / k;
        int r = n % k;
        for (int i = 0; i < k; i++) {
            ListNode* curHead = cur;
            for (int j = 0; j < d + (r > 0) - 1; j++) {
                if (cur != nullptr) {
                    cur = cur -> next;
                }
            }
            if (cur != nullptr) {
                ListNode* prev = cur;
                cur = cur -> next;
                prev -> next = nullptr;
            }
            ans[i] = curHead;
            r--;
        }
        return ans;
    }
};
