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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return rec(l1, l2, 0);
    }
    //main idea, add the numbers together and keep track of a carry
    //which is gonna be either 0 or 1
    
    public ListNode rec(ListNode p1, ListNode p2, int carry) {
        if (p1 == null && p2 == null) { //if both null we are done
            if (carry > 0) { 
                p1 = new ListNode(carry); 
            }
            return p1;
        }
        if (p1 != null && p2 == null) { //only p2 is null
            p1.val += carry;
            carry = p1.val / 10;
            p1.val = p1.val % 10;
            p1.next = rec(p1.next, p2, carry);
            return p1;
        }
        else if (p1 == null && p2 != null) { //only p1 is null
            p2.val += carry;
            carry = p2.val / 10;
            p2.val = p2.val % 10;
            p2.next = rec(p1, p2.next, carry);
            return p2;
        }
        else { //both p1 and p2 are not null
            p1.val += p2.val + carry; //add them up
            carry = p1.val / 10; //set the new carry
            p1.val = p1.val % 10; //update the value to be only 1 digit
            p1.next = rec(p1.next, p2.next, carry);
            return p1;
        }
    } 
}
