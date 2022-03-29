class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = 0
        st1 = st2 = ""
        for a, b in zip(s1, s2):
            if a != b:
                cnt += 1
                st1 += a
                st2 += b
        if cnt == 0: return True
        if cnt != 2: return False
        return st1 == st2[::-1]
