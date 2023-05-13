class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        mat = []
        for row in nums:
            mat.append(sorted(row)[::-1])
        
        ans = 0
        for j in range(len(mat[0])):
            cur = 0
            for i in range(len(mat)):
                cur = max(cur, mat[i][j])
            ans += cur
        return ans
