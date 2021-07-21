# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        
        def dfs(root, tail):
            if root is None:
                return tail
            res = dfs(root.left, root)
            root.left = None
            root.right = dfs(root.right, tail)
            
            return res
        
        return dfs(root, None)
