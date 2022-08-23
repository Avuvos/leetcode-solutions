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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* pos = head;
        while (pos != NULL) {
            stk.push(pos -> val);
            pos = pos -> next;
        }
        
        while (head != NULL && !stk.empty()) {
            if (head -> val != stk.top()) return false;
            stk.pop();
            head = head -> next;
        }
        return true;
    }
};
