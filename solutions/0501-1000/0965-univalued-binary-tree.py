# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        
        if root is None:
            return True
        
        def dfs(root, value):
            if root is None:
                return True
            if root.val != value:
                return False
            return dfs(root.left, value) and dfs(root.right, value)
            
            
        return dfs(root, root.val)
