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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* current = head;
        while (current != nullptr && current -> next != nullptr) {
            if (s.contains(current -> next -> val)) {
                current -> next = current -> next -> next;
            } else {
                current = current -> next;
            }
        }
        if (s.contains(head -> val)) {
            return head -> next;
        }
        return head;
    }
};
