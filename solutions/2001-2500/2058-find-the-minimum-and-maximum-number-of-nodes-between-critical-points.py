# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        pos = head
        prev = None
        res = [float('inf'), float('-inf')]
        crit = []
        idx = 1
        while pos != None and pos.next != None:
            if prev != None:
                if pos.val > prev.val and pos.val > pos.next.val:
                    crit.append(idx)
                elif pos.val < prev.val and pos.val < pos.next.val:
                    crit.append(idx)
            prev = pos
            pos = pos.next
            idx += 1
            if len(crit) >= 2 and crit[-1] - crit[-2] < res[0]:
                res[0] = crit[-1] - crit[-2]
                
        if len(crit) >= 2:
            res[1] = crit[-1] - crit[0]
            return res
        else:
            return [-1, -1]
