# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        
        L =[0]
        def dfs(root):
            if root is not None:
                dfs(root.right)
                L[0] += root.val
                root.val = L[0]
                dfs(root.left)
        dfs(root)
        return root
