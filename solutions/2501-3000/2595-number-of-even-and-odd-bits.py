class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        s = (bin(n))[::-1]
        print(s)
        ans = [0, 0]
        for i, x in enumerate(s):
            if x == '1':
                if i & 1: ans[1] += 1
                else: ans[0] += 1
        return ans
