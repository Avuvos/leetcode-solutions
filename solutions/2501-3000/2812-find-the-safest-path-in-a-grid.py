class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        INF = 10**12
        dp = [[INF for i in range(n)] for j in range(n)]
        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dp[i][j] = 0
                    q.append((i, j))
        
        while q:
            sz = len(q)
            for _ in range(sz):
                i, j = q.popleft()
                if i + 1 < n and dp[i + 1][j] >= INF:
                    dp[i + 1][j] = 1 + dp[i][j];
                    q.append((i + 1, j))
                if i - 1 >= 0 and dp[i - 1][j] >= INF:
                    dp[i - 1][j] = 1 + dp[i][j];
                    q.append((i - 1, j))
                if j + 1 < n and dp[i][j + 1] >= INF:
                    dp[i][j + 1] = 1 + dp[i][j];
                    q.append((i, j + 1))
                if j - 1 >= 0 and dp[i][j - 1] >= INF:
                    dp[i][j - 1] = 1 + dp[i][j];
                    q.append((i, j - 1))    
        
        # print(dp)
        
        def ok(i, j, d):
            if i == n - 1 and j == n - 1:
                return True
            if seen[i][j]:
                return False
            seen[i][j] = True
            ans = False
            if i + 1 < n and dp[i + 1][j] >= d:
                ans |= ok(i + 1, j, d)
            if i - 1 >= 0 and dp[i - 1][j] >= d:
                ans |= ok(i - 1, j, d)
            if j + 1 < n and dp[i][j + 1] >= d:
                ans |= ok(i, j + 1, d)
            if j - 1 >= 0 and dp[i][j - 1] >= d:
                ans |= ok(i, j - 1, d)
            return ans
        
        left = 0
        right = INF
        ans = 0
        
        while left <= right:
            mid = left + (right - left)//2
            seen = [[False for i in range(n)] for j in range(n)]
            
            if dp[0][0] >= mid and ok(0, 0, mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return ans
            
            
            
            
