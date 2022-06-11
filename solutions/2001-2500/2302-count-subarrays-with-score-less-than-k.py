class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        res = 0
        s = 0
        left = 0
        for right, num in enumerate(nums):
            s += num
            while (right - left + 1) * s >= k:
                s -= nums[left]
                left += 1
            res += (right - left + 1)
        return res
