class Solution:
    def countElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = 0
        i = 0
        # 1 2 2 5 len=4
        # 0 1 2 3
        #
        while i < len(nums):
            cnt = 1
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                cnt += 1
                i += 1
            if len(nums) - (i + 1) >= k:
                res += cnt
            i += 1
        return res
