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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr && cur -> next != nullptr) {
            int g = gcd(cur -> val, cur -> next -> val);
            ListNode* tmp = cur -> next;
            cur -> next = new ListNode(g);
            cur -> next -> next = tmp;
            cur = tmp;
        }
        return head;
    }
};
