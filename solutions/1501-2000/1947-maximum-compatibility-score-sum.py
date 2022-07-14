class Solution:
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        n = len(students)
        scores = [[0 for _ in range(n)] for _ in range(n)]
        #scores[i][j] = score of student i with mentor j
        for i in range(n):
            for j in range(n):
                scores[i][j] = sum(1 for a, b in zip(students[i], mentors[j]) if a == b)
                
        used = [False] * n
        
        def dfs(student):
            if student >= n:
                return 0
            res = 0
            for mentor in range(n):
                if used[mentor]: continue
                used[mentor] = True
                cur = scores[student][mentor] + dfs(student + 1)
                used[mentor] = False
                res = max(res, cur)
            return res
        
        return dfs(0)
