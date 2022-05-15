class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:

        def anagrams(s, t):
            return Counter(s) == Counter(t)

        prev = words[0]
        res = [prev]
        for i in range(1, len(words)):
            if anagrams(words[i], prev):
                continue
            else:
                prev = words[i]
                res.append(prev)
        return res
