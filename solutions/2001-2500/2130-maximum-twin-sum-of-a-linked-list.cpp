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
    int pairSum(ListNode* head) {
        ListNode* rabbit = head;
        ListNode* turtle = head;
        
        while (rabbit != nullptr && rabbit -> next != nullptr) {
            rabbit = rabbit -> next -> next;
            turtle = turtle -> next;
        }
        
        ListNode* prev = nullptr;
        ListNode* start = turtle;
        while (turtle != nullptr) {
            ListNode* tmp = turtle -> next;
            turtle -> next = prev;
            prev = turtle;
            turtle = tmp;
            start = prev;
        }
        
        ListNode* cur = head;
        int ans = 0;
        while (start != nullptr) {
            ans = max(ans, cur -> val + start -> val);
            start = start -> next;
            cur = cur -> next;
        }
        return ans;
        
    }
};
