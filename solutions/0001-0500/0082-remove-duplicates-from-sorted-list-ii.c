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
    struct ListNode* prev = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* dummy = prev;
    prev -> next = head;
    prev -> val = 0;
    struct ListNode* cur = head;
    while (cur != NULL && cur -> next != NULL) {
        int del = 0;
        while (cur != NULL && cur -> next != NULL && cur -> val == cur -> next -> val) {
            cur = cur -> next;
            del = 1;
        }
        if (del) {
            prev -> next = cur -> next;
        } else {
            prev = prev -> next;
        }
        cur = cur -> next;
    }
    return dummy -> next;
    
}
