class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            l = []
            while x > 0:
                l.append(x % 10)
                x = x//10
            l.reverse()
            for y in l:
                res.append(y)
        return res
