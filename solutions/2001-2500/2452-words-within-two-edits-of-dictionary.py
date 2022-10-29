class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        
        def f(s1, s2):
            return len([1 for a, b in zip(s1, s2) if a != b]) <= 2
        res = []
        for word in queries:
            good = False
            for target in dictionary:
                good |= f(word, target)
            if good:
                res.append(word)
        return res
