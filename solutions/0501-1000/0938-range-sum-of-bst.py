# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        
        def dfs(root, low, high):
            if root is None:
                return 0
            value = 0
            if root.val >= low and root.val <= high:
                value = root.val
            return value + dfs(root.left, low, high) + dfs(root.right, low, high)
        
        return dfs(root, low, high)
