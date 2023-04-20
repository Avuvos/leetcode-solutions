# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = [(root, 0, 0)]
        left = lvl = res = 0
        for node, depth, pos in q:
            if node is not None:
                q.append((node.left, depth+1, pos*2))
                q.append((node.right, depth+1, pos*2 + 1))
                if lvl != depth:
                    lvl = depth
                    left = pos
                res = max(pos - left + 1, res) 
        return res
                
