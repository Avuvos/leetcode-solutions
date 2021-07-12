# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        L1 = []
        L2 = []
        
        def dfs(root, L):
            if root:
                if root.left is None and root.right is None:
                    L.append(root.val)
                dfs(root.left, L)
                dfs(root.right, L)
            
        dfs(root1, L1)
        dfs(root2, L2)
        if len(L1) != len(L2):
            return False
        for i in range(0, len(L1)):
            if L1[i] != L2[i]:
                return False
        return True
            
