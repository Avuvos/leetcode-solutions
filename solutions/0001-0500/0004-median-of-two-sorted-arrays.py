class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        x = nums1 + nums2
        x.sort()
        n = len(x)
        if n == 1:
            return x[0]
        return x[n // 2] if n & 1 else (x[n//2 - 1] + x[n//2]) / 2
