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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL) return head;
        ListNode* odd_head = head;
        ListNode* prev_odd_head = NULL;
        ListNode* save_even_head = head -> next;
        ListNode* even_head = head -> next;

        while (odd_head != NULL && even_head != NULL) {
            prev_odd_head = odd_head;
            odd_head -> next = even_head -> next;
            odd_head = odd_head -> next;
            if (odd_head == NULL) break;
            even_head -> next = odd_head -> next;
            even_head = even_head -> next;
        }
        if (odd_head == NULL)
            prev_odd_head -> next = save_even_head;
        else
            odd_head -> next = save_even_head;
        return head;
    }
};
