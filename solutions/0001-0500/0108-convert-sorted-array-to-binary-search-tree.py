# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        
        def rec(nums, left, right):
            if left > right:
                return None
            else:
                mid = (left+right)//2
                root = TreeNode(nums[mid])
                root.left = rec(nums, left, mid-1)
                root.right = rec(nums, mid+1, right)
                return root
            
        n = len(nums)
        left = 0
        right = n-1
        return rec(nums, left, right)
