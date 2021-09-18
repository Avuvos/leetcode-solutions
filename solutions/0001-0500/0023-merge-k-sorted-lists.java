/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        if (lists.length == 1) return lists[0];
        
        ListNode head = merge2(lists[0], lists[1]);
        for (int i=2; i<lists.length; i++) {
            head = merge2(head, lists[i]);
        }
        return head;
    }
    
    public ListNode merge2(ListNode p1, ListNode p2) {
        if (p1 == null && p2 == null) {
            return null;
        }
        else if (p1 != null && p2 == null) {
            return p1;
        }
        else if (p1 == null && p2 != null) {
            return p2;
        }
        else {
            if (p1.val <= p2.val) {
                p1.next = merge2(p1.next, p2);
                return p1;
            }
            else {
                p2.next = merge2(p1, p2.next);
                return p2;
            }
        }
        
    }
}
