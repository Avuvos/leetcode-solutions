class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        s = ['a', 'e', 'i', 'u', 'o']
        ans = 0
        for i in range(left, right + 1):
            if words[i][0] in s and words[i][-1] in s:
                ans += 1
        return ans
