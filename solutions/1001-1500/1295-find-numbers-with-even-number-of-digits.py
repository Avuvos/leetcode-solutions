class Solution(object):
    def findNumbers(self, nums):
        res = 0
        for i, x in enumerate(nums):
            if len(str(x)) % 2 == 0:
                res += 1
        return res
        
