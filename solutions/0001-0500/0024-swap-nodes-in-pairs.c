/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    struct ListNode* nxt = head -> next;
    head -> next = swapPairs(nxt -> next);
    nxt -> next = head;
    
    return nxt;
}
