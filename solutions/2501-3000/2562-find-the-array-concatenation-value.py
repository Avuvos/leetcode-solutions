class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        res = 0
        l = 0
        r = len(nums) - 1
        while l <= r:
            if l == r:
                res += nums[l]
                break
            cur = str(nums[l]) + str(nums[r])
            res += int(cur)
            l += 1
            r -= 1
        return res
