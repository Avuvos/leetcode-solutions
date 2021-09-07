# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        
        def build(nums):
            if len(nums) == 0:
                return None;
            if len(nums) == 1:
                return TreeNode(nums[0])
            maxVal = max(nums)
            maxIndex = nums.index(maxVal)
            node = TreeNode(maxVal)
            node.left = build(nums[0:maxIndex]) 
            node.right = build(nums[maxIndex+1:])
            return node
        
        return build(nums)
