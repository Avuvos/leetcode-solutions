class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        d = gcd(0, numsDivide[0])
        for i in range(1, len(numsDivide)):
            d = gcd(d, numsDivide[i])
        nums.sort()
        res = 0
        for x in nums:
            if d % x == 0:
                return res
            res += 1
        return -1
