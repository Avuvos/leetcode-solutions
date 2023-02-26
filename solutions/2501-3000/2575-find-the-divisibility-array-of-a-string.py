class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        n = len(word)
        ans = [0]*n
        cur = 0
        for i, c in enumerate(word):
            cur *= 10
            cur += int(c)
            if cur % m == 0:
                ans[i] = 1
            cur %= m
        return ans
