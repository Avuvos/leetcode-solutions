class Solution:
    def maximumRows(self, mat: List[List[int]], cols: int) -> int:

        best = 0
        mask = [0] * (len(mat[0]))
        def backtrack(cols_left, index):
            nonlocal best
            if cols_left == 0 or index >= len(mat[0]):
                if cols_left > 0: return
                curr = 0
                for i in range(len(mat)):
                    row_good = True
                    for j in range(len(mat[0])):
                        if mat[i][j] == 1 and mask[j] == 0:
                            row_good = False
                            break
                    if row_good:
                        curr += 1
                best = max(best, curr)
                return
            backtrack(cols_left , index + 1)
            mask[index] = 1
            backtrack(cols_left - 1, index + 1)
            mask[index] = 0
            
        backtrack(cols, 0)
        return best
