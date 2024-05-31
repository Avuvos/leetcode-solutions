/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* tmp = node -> next;
    int tmp_val = tmp -> val;
    tmp -> val = node -> val;
    node -> val = tmp_val;
    node -> next = tmp -> next;
    free(tmp);
}
