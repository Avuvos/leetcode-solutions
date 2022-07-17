class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        # encode every matrix state as a binary number
        # map the binary number to true/false (visited)
        # simply brute force on every option if it was not visited before

        def zero_matrix(matrix):
            for i in range(len(matrix)):
                for j in range(len(matrix[0])):
                    if matrix[i][j] == 1:
                        return False
            return True

        def grid_to_binary(matrix):
            s = ""
            for i in range(len(matrix)):
                for j in range(len(matrix[0])):
                    s += str(matrix[i][j])
            return s

        def flip_cell(matrix, i, j):
            matrix[i][j] = abs(matrix[i][j] - 1)

        def flip_neighbors(matrix, i, j):
            flip_cell(matrix, i, j)
            for x, y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                if 0 <= x < len(matrix) and 0 <= y < len(matrix[0]):
                    flip_cell(matrix, x, y)

        memo = {}
        seen = set()
        def dfs(matrix):
            if zero_matrix(matrix):
                return 0
            state = grid_to_binary(matrix)
            if state in memo:
                return memo[state]
            if state in seen:
                return float('inf')
            seen.add(state)
            best = float('inf')
            for i in range(len(matrix)):
                for j in range(len(matrix[0])):
                    flip_neighbors(matrix, i, j)
                    cur = 1 + dfs(matrix)
                    best = min(best, cur)
                    flip_neighbors(matrix, i, j)  # backtracking
            memo[state] = best
            return best

        res = dfs(mat)
        return res if res < float('inf') else -1
