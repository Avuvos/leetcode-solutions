class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            return 0 if nums1 == nums2 else -1
        
        sub = 0
        add = 0
        for (a, b) in zip(nums1, nums2):
            if a == b: continue
            if abs(b - a) % k != 0:
                return -1
            if b > a:
                add += (b-a)//k
            else:
                sub += (a-b)//k
        if sub != add:
            return -1
        return add
