class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if target not in words:
            return -1
        ind = []
        for i, w in enumerate(words):
            if w == target:
                ind.append(i)
        n = len(words)
        res = n
        for index in ind:
            res = min(res, abs(startIndex - index), n - abs(startIndex - index))
        return res
            
