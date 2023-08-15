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
    ListNode* partition(ListNode* head, int x) {
        ListNode* big = new ListNode();
        ListNode* small = new ListNode();
        
        ListNode* s = small;
        ListNode* b = big;
        while (head != nullptr) {
            if (head -> val < x) {
                s -> next = new ListNode(head -> val);
                s = s -> next;
            } else {
                b -> next = new ListNode(head -> val);
                b = b -> next;
            }
            head = head -> next;
        }
        s -> next = big -> next;
        ListNode* ans = small -> next;
        return ans;
    }
};
