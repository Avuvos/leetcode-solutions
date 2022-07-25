class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        nums = set(nums)
        bit_counts = sorted([x.bit_count() for x in nums])
        n = len(bit_counts)
        res = 0

        for index, bit_cnt in enumerate(bit_counts):
            left = index + 1
            right = n
            while left < right:
                mid = (left + right) // 2
                if bit_counts[mid] + bit_cnt >= k:
                    right = mid
                else:
                    left = mid + 1  
            res += (n - left)*2


        for x in nums:
            if (x & x).bit_count() + (x | x).bit_count() >= k:
                res += 1

        return res
