class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        n = len(s)
        ab = "abcdefghijklmnopqrstuvwxyz"[0:k]
        s = [c for c in s]
        if n == 1:
            for c in ab:
                if c > s[0]:
                    return c
            return ""
        for i in range(n - 1, -1, -1):
            for c in ab:
                if c <= s[i]: continue
                if i - 1 >= 0 and s[i - 1] == c: continue
                if i - 2 >= 0 and s[i - 2] == c: continue
                s[i] = c
                for j in range(i + 1, n):
                    for d in ab:
                        if j - 1 >= 0 and s[j - 1] == d: continue
                        if j - 2 >= 0 and s[j - 2] == d: continue
                        s[j] = d
                        break
                return "".join(s)
            
        return ""
