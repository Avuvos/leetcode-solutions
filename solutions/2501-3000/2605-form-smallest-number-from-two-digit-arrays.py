class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        d = 1
        for num in range(1, 100):
            digits = []
            x = num
            while x > 0:
                digits.append(x % 10)
                x = x // 10
            arr1 = False
            arr2 = False
            for d in digits:
                if d in nums1: arr1 = True
                if d in nums2: arr2 = True
            if arr1 and arr2:
                return num
        return -1
