class Solution:
    def greatestLetter(self, s: str) -> str:
        t = string.ascii_uppercase
        a = string.ascii_lowercase
        for i in range(len(t) - 1, -1, -1):
            if t[i] in s and a[i] in s:
                return t[i]
        return ""
