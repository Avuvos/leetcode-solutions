class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        forbidden = set(forbidden)        
        seen = [False for _ in range(10000)]
        queue = [(0, True)] #the bool means it can jump backwards now
        res = 0
        
        while queue:
            size = len(queue)
            for i in range(size):
                pos, canJumpBack = queue.pop(0)
                if pos == x:
                    return res
                if pos >= len(seen) or seen[pos] or pos in forbidden:
                    continue
                seen[pos] = True
                if canJumpBack and pos - b >= 0:
                    queue.append((pos - b, False))
                queue.append((pos + a, True))
            res += 1
            
        return -1
        
        
        
        
