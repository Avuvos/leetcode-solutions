class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)
        s = set()
        a = 0
        b = 0
        while (a < len(nums1) and b < len(nums2)):
            if (nums1[a] == nums2[b]):
                s.add(nums1[a])
                a += 1
                b += 1
            elif (nums1[a] > nums2[b]):
                b += 1
            else:
                a += 1
        
        return list(s)
