# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        
        def dfs(root, su, msg):
            if root is None:
                return 0
            msg += str(root.val)
            if root.left is None and root.right is None:
                return su + int(msg, 2) 
            return dfs(root.left, su, msg) + dfs(root.right, su, msg)
        return dfs(root, 0, "")
