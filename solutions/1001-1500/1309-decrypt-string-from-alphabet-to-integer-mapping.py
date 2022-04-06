class Solution:
    def freqAlphabets(self, s: str) -> str:
        res = ""
        i = 0
        while i < len(s):
            if i + 2 < len(s) and s[i + 2] == "#":
                num = int(s[i] + s[i + 1])
                i += 2
            else:
                num = int(s[i])
            res += chr(97 + num - 1)
            i += 1
        return res
