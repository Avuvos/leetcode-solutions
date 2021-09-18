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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode groupPrev = dummyHead;
        
        while (true) {
            ListNode kthNode = getKth(groupPrev, k);
            if (kthNode == null) { //Kth node is null so we finished
                break;
            }
            
            ListNode nextGroup = kthNode.next;
            
            
            ListNode prev = kthNode.next; //reverse untill the kth node
            ListNode pos = groupPrev.next;
            while (pos != nextGroup) {
                ListNode tmp = pos.next;
                pos.next = prev;
                prev = pos;
                pos = tmp;
            }
            
            ListNode tmp2 = groupPrev.next; //swap our pointers accordingly
            groupPrev.next = kthNode;
            groupPrev = tmp2;
        }
        return dummyHead.next;
    }
    
    //Find the kth node, if its null it means we are done
    public ListNode getKth(ListNode curr, int k) {
        while (curr != null && k > 0) {
            curr = curr.next;
            k--;
        }
        return curr;
    }
    
}
