# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        
        @cache
        def dfs(l, r):
            if l > r:
                return [None]
            ans = []
            for x in range(l, r + 1): #x is a root
                left = dfs(l, x - 1)
                right = dfs(x + 1, r)
                ans += [TreeNode(x, y, z) for y in left for z in right]
            return ans
        
        return dfs(1, n)
            
