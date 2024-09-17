class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        c1 = Counter(s1.split(" "))
        c2 = Counter(s2.split(" "))
        ans = [key for key, val in c1.items() if key not in c2 and val == 1]
        ans += [key for key, val in c2.items() if key not in c1 and val == 1]
        return ans
