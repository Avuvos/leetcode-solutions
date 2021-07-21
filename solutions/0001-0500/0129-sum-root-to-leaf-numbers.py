# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        
        def dfs(root, curr):
            if root is None:
                return 0
                     
            if root.left is None and root.right is None:
                curr += str(root.val)
                return int(curr)
            
            left = dfs(root.left, curr+str(root.val))
            right = dfs(root.right, curr+str(root.val))
            
            return left + right
        
        return dfs(root, "")
