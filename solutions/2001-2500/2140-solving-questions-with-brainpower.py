class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        @cache
        def dfs(index):
            if index >= n:
                return 0
            take = questions[index][0] + dfs(index + questions[index][1] + 1)
            skip = dfs(index + 1)
            return max(take, skip)
        return dfs(0)
