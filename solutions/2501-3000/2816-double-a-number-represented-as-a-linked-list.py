# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        def revList(head):
            cur = head
            prev = None
            while cur:
                tmp = cur.next
                cur.next = prev
                prev = cur
                cur = tmp
            return prev
        
        head = revList(head)
        cur = head
        carry = 0
        prev = cur
        while cur:
            value = cur.val + cur.val + carry
            carry = 0
            if value >= 10: 
                carry = 1
            value %= 10
            cur.val = value
            prev = cur
            cur = cur.next
        if carry:
            prev.next = ListNode(1)
            
        head = revList(head)
        return head
