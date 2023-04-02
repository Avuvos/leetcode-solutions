class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = zero = ones = 0
        z = True
        i = 0
        n = len(s)
        while i < n:
            zero = ones = 0
            while i < n and s[i] == '0':
                zero += 1
                i += 1
            while i < n and s[i] == '1':
                ones += 1
                i += 1
            ans = max(ans, 2*min(zero, ones))
            # i += 1
        return ans
