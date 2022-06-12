class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]
        for row in range(m - 2, -1, -1):
            for index in range(n):
                node = grid[row][index] #target
                for neib in range(n):
                    dist[row][index] = min(dist[row][index],
                                              node + grid[row + 1][neib] + moveCost[node][neib])
                grid[row][index] = dist[row][index]
        #print(dist)
        return min(dist[0][k] for k in range(n))
