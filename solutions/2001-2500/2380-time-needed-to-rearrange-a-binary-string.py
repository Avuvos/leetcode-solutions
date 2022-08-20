class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        res = 0
        new_s = ""
        while True:
            found = False
            for i in range(len(s) - 1):
                if s[i] == '0' and s[i + 1] == '1':
                    found = True
                    break
            if not found:
                return res
            res += 1
            s = s.replace("01", "10")
