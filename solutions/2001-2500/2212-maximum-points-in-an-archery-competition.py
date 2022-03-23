class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        res = [0] * 12
        best = [0]
        
        def backtrack(idx, left, score, path):
            if idx < 0 or left <= 0:
                path[0] += max(0, left)
                if score > best[0]:
                    best[0] = score
                    for i,x in enumerate(path):
                        res[i] = x
                return
            if left >= aliceArrows[idx] + 1:
                path[idx] = aliceArrows[idx] + 1
                backtrack(idx-1, left-(aliceArrows[idx]+1), score + idx, path)
                path[idx] = 0
            backtrack(idx-1, left, score, path)
            path[idx] = 0
        
        backtrack(11, numArrows, 0, [0] * 12)
        return res
