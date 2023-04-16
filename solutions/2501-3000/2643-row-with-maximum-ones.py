class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans = [0, 0]
        for idx, row in enumerate(mat):
            if row.count(1) > ans[1]:
                ans[1] = row.count(1)
                ans[0] = idx
        return ans
