class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        d = defaultdict(int)
        for a, b in nums1:
            d[a] += b
        for a, b in nums2:
            d[a] += b
        return sorted(d.items())
