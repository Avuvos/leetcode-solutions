/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        if (!AreMerged(headA, headB)) return null;
        
        ListNode p1 = headA;
        ListNode p2 = headB;
        while(p1 != null  && p2 != null) {
            if (p1.equals(p2)) return p1;
            p1 = p1.next;
            p2 = p2.next;
            if (p1 == null) {
                p1 = headB;
            }
            if (p2 == null) {
                p2 = headA;
            }
        }
        return null;
    }   
    public boolean AreMerged(ListNode p1, ListNode p2) {
        if (p1.equals(p2)) return true;
        if (p1 == null || p2 == null) return false;
        
        while (p1.next != null) {
            p1 = p1.next;    
        }
        while (p2.next != null) {
            p2 = p2.next;
        }
        return p1.equals(p2);
        
    }
}
