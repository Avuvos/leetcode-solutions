class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        unique = set()
        s = left = res = 0
        for right in range(len(nums)):
            s += nums[right]
            while nums[right] in unique:
                unique.remove(nums[left])
                s -= nums[left]
                left += 1
            unique.add(nums[right])
            res = max(res, s)
        return res
