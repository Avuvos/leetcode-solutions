class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        res = ""
        for i in range(n - 2):
            if num[i] == num[i + 1] and num[i + 1] == num[i + 2]:
                res = max(res, 3*num[i])
        return res
