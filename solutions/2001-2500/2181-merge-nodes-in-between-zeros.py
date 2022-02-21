# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        pos = head.next

        while pos is not None:
            if pos.val != 0:
                node.val += pos.val
            else:
                if pos.next == None:
                    node.next = None
                else:
                    node.next = pos
                    node = pos
            
            pos = pos.next
            
            
        return head
