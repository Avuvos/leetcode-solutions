# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        
        answer = []
        
        def dfs(root, st):
            if root is None:
                return None
            if root.left is None and root.right is None:
                answer.append(st+str(root.val))
            else:
                s = str(root.val)+"->"
                dfs(root.left, st+s)
                dfs(root.right, st+s)
                
        dfs(root, "")
        return answer
