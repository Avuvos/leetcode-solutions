class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        L = []
        for lst in matrix:
            for num in lst:
                L.append(num)
        L = sorted(L)
        return L[k-1]
        
