class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        w2 = sorted(words, key = lambda x: [order.index(c) for c in x])
        return words == w2
