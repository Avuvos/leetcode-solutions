# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
      
        def rec(root1, root2):
            if root1 is None and root2 is None:
                return None
            if root1 is not None and root2 is not None:
                root1.val += root2.val
                root1.left = rec(root1.left, root2.left)
                root1.right = rec(root1.right, root2.right)
                return root1
            return root1 or root2
            

        return rec(root1,root2)
       
