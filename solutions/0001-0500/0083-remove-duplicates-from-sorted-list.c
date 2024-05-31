/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    struct ListNode* prev = head;
    struct ListNode* cur = head -> next;
    while (cur != NULL) {
        if (prev -> val == cur -> val) {
            prev -> next = cur -> next;
        } else {
            prev = cur;
        }
        cur = cur -> next;
    }
    return head;
}
