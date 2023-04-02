class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for x in nums:
            found = False
            for l in ans:
                if x not in l:
                    found = True
                    l.append(x)
                    break
            if not found:
                ans.append([x])
        return ans
