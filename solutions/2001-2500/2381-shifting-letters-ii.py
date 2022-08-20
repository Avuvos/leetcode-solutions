class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        low = ascii_lowercase
        prefix_forward = [0] * (n + 1)
        prefix_backward = [0] * (n + 1)

        for l, r, d in shifts:
            if d == 0:
                prefix_backward[r + 1] -= 1
                prefix_backward[l] += 1
            else:
                prefix_forward[r + 1] -= 1
                prefix_forward[l] += 1

        for i in range(1, len(prefix_forward)):
            prefix_forward[i] += prefix_forward[i - 1]

        for i in range(1, len(prefix_backward)):
            prefix_backward[i] += prefix_backward[i - 1]

        prefix = [a - b for a, b in zip(prefix_forward, prefix_backward)]
        
        res = ""
        mp = {}
        i = 0
        for c in low:
            mp[c] = i
            i += 1

        for index, c in enumerate(s):
            res += low[(mp[c] + prefix[index]) % 26]
        return res
