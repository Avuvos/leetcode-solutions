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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return pre -> next;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = head;
        node = reverseList(node);
        ListNode* head2 = node;
        vector<int> mx;
        while (node != nullptr) {
            if (mx.empty()) {
                mx.push_back(node -> val);
            } else {
                mx.push_back(max(mx.back(), node -> val));
            }
            node = node -> next;
            //cout << "max.back = " << mx.back() << endl;
        }
        node = reverseList(head2);
        reverse(mx.begin(), mx.end());
        int index = 0;
        while (node != nullptr) {
            //cout << "node val is " << node -> val << "max to the right is " << mx[index] << endl;
            if (node -> val < mx[index]) {
                node = node -> next;
            } else break;
            index++;
        }
        ListNode* prev = nullptr;
        ListNode* res = node;         
        while (node != nullptr) {
            if (node -> val < mx[index]) {
                prev -> next = node -> next;
                node = node -> next;
                //delete
            }else {
                prev = node;
                node = node -> next;
            }
            index++;
            
        }
        return res;
    }
};
