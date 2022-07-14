# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
        #find the root value in the inorder traversal
        #set root.left to be recursion call on the left side of the array
        #set root.right to be recursion call on the right side of the array
        #use map to find the index efficiently
        #pointer to traverse the preorder array, inc by one every time we create a new root
        
        inorder_map = {val : idx for idx, val in enumerate(inorder)}
        pre_index = 0
        
        def dfs(left, right):
            nonlocal pre_index
            if left > right:
                return None 
            root = TreeNode(preorder[pre_index])
            pre_index += 1
            root_index = inorder_map[root.val]               
            root.left = dfs(left, root_index - 1)
            root.right = dfs(root_index + 1, right)
            return root
        
        return dfs(0, len(inorder) - 1)
