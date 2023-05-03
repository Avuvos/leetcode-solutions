class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        return [[a for a in set(nums1) if a not in set(nums2)], 
                [a for a in set(nums2) if a not in set(nums1)]]
