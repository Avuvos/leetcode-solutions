/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* first_node = head;
    for (int i = 0; i < k - 1; i++) {
        first_node = first_node -> next;
    }
    struct ListNode* fast = first_node;
    struct ListNode* second_node = head;
    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next;
        second_node = second_node -> next;
    }
    
    int tmp = first_node -> val;
    first_node -> val = second_node -> val;
    second_node -> val = tmp;
    return head;
    
}
