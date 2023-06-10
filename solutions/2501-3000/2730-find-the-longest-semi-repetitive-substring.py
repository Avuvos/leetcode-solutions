class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        left = ans = 0
        multi = set()
        for right in range(len(s)):
            if right - 1 >= 0 and s[right - 1] == s[right]:
                multi.add(right - 1)
            while len(multi) > 1:
                if left in multi:
                    multi.remove(left)
                left += 1
            ans = max(ans, right - left + 1)
        return ans
