class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = 0
        streak = 0
        for n in nums:
            if n == 0:
                streak += 1
            else:
                res += (streak*(streak+1)) //2
                streak = 0
        return res + (streak*(streak+1)) //2
