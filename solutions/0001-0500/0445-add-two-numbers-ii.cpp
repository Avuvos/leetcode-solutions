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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto rev = [&](ListNode* lst) {
            ListNode* prev = nullptr;
            ListNode* cur = lst;
            while (cur != nullptr) {
                ListNode* temp = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = temp;
            }
            return prev;
        };
        l1 = rev(l1);
        l2 = rev(l2);
        
        
        
        int s = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (l1 || l2) {
            if (l1 != nullptr) {
                s += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr) {
                s += l2 -> val;
                l2 = l2 -> next;
            }
            ans -> val = s % 10;
            carry = s / 10;
            ListNode* head = new ListNode(carry);
            head -> next = ans;
            ans = head;
            s = carry;
        }
        return carry == 0 ? ans -> next : ans;
    }
};
