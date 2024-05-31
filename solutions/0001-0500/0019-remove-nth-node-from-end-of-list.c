/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode* dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyHead -> next = head;
    dummyHead -> val = 0;
    
    struct ListNode* slow = dummyHead;
    struct ListNode* fast = dummyHead;
    
    while (n--) {
        fast = fast -> next;
    }
    
    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next;
        slow = slow -> next;
    }
    
    slow -> next = slow -> next -> next;
    return dummyHead -> next;
}
