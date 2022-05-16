class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        fire = [[float('inf') for _ in range(n)] for _ in range(m)]

        # speard the fire and fill the "fire" array
        def bfsFire():
            q = deque()
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1:
                        q.append((i, j))
            dist = 0
            while q:
                size = len(q)
                for _ in range(size):
                    i, j = q.popleft()
                    if fire[i][j] != float('inf'):
                        continue
                    fire[i][j] = dist
                    if i < m - 1 and grid[i + 1][j] == 0 and fire[i + 1][j] == float('inf'): q.append((i + 1, j))
                    if i > 0 and grid[i - 1][j] == 0 and fire[i - 1][j] == float('inf'): q.append((i - 1, j))
                    if j < n - 1 and grid[i][j + 1] == 0 and fire[i][j + 1] == float('inf'): q.append((i, j + 1))
                    if j > 0 and grid[i][j - 1] == 0 and fire[i][j - 1] == float('inf'): q.append((i, j - 1))
                dist += 1

        # check if we can reach the house after waiting "time" time
        def bfsCanReach(time):
            q = deque()
            q.append((0, 0))
            curGrid = [[grid[i][j] for j in range(n)] for i in range(m)]
            while q:
                size = len(q)
                for _ in range(size):
                    i, j = q.popleft()
                    if i == m - 1 and j == n - 1 and time <= fire[i][j]:
                        return True
                    if fire[i][j] <= time or curGrid[i][j] == "#":
                        continue
                    curGrid[i][j] = "#"
                    if i < m - 1 and curGrid[i + 1][j] == 0: q.append((i + 1, j))
                    if i > 0 and curGrid[i - 1][j] == 0: q.append((i - 1, j))
                    if j < n - 1 and curGrid[i][j + 1] == 0: q.append((i, j + 1))
                    if j > 0 and curGrid[i][j - 1] == 0: q.append((i, j - 1))
                time += 1
            return False

        bfsFire()

        # edge cases
        canReachHouse = bfsCanReach(0)
        if not canReachHouse:
            return -1
        if canReachHouse and fire[m - 1][n - 1] == float('inf'):
            return 10 ** 9

        # binary search to find best time
        left, right = 0, 10 ** 9
        while left < right:
            mid = (left + right + 1) // 2
            if bfsCanReach(mid):
                left = mid
            else:
                right = mid - 1
        return left
