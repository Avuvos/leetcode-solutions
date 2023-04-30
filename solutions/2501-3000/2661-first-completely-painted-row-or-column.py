class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        mp = defaultdict(int)
        n = len(mat)
        m = len(mat[0])
        rowScore = [0 for _ in range(n)]
        colScore = [0 for _ in range(m)]
        
        for i in range(n):
            for j in range(m):
                mp[mat[i][j]] = (i, j)
                
        for index, a in enumerate(arr):
            i, j = mp[a]
            rowScore[i] += 1
            colScore[j] += 1
            if rowScore[i] == m or colScore[j] == n:
                return index
        return -1
