class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        left = 0
        right = 0 + k
        sol = float('inf')
        while right <= len(blocks):
            w = 0
            for i in range(left, right):
                if blocks[i] == 'W':
                    w += 1
            left += 1
            right += 1
            sol = min(sol, abs(w))
        return sol
