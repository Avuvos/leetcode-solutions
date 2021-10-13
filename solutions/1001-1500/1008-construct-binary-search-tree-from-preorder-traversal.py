# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        
        def build(root, preorder):
            if len(preorder) == 0:
                return root    
            root = TreeNode(preorder[0])
            root.left = build(root.left, [r for r in preorder if r < root.val])
            root.right = build(root.right, [r for r in preorder if r > root.val])
            return root
        
        return build(None, preorder)
