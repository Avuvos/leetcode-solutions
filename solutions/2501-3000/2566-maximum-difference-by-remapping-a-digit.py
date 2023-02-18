class Solution:
    def minMaxDifference(self, num: int) -> int:
        mx = num
        mn = num
        swapped = -1
        nxt = ""
        for c in str(num):
            if c != '9' and swapped == -1:
                nxt += '9'
                swapped = c
            elif c == swapped:
                nxt += '9'
            else:
                nxt += c
        mx = max(mx, int(nxt))
        swapped = -1
        nxt = ""
        for c in str(num):
            if c != 0 and swapped == -1:
                nxt += '0'
                swapped = c
            elif c == swapped:
                nxt += '0'
            else:
                nxt += c
        mn = min(mn, int(nxt))
        return mx - mn
