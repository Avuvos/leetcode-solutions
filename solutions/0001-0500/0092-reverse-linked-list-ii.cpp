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
    ListNode* reverseBetween(ListNode* head, int left, int right) {        
        int index = 1;
        ListNode* dummy = new ListNode(0, head);
        ListNode *prev = dummy, *current = nullptr, *tmp = nullptr;
        while (index < left) {
            prev = prev -> next;
            index++;
        }
        
        current = prev -> next;
        while (index < right) {
            tmp = prev -> next;
            prev -> next = current -> next;
            current -> next = current -> next -> next;
            prev -> next -> next = tmp;
            index++;
        }
        
        return dummy -> next;
    }
};
