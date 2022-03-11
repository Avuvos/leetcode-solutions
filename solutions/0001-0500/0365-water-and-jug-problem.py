class Solution:
    def canMeasureWater(self, j1p: int, j2p: int, target: int) -> bool:
        q = deque([(j1p, j2p)])
        seen = set()
        
        while q:
            size = len(q)
            for i in range(size):
                j1, j2 = q.popleft()
                if j1 + j2 == target:
                    return True
                nextMoves = set()
                nextMoves.add((j1p, j2)) 
                nextMoves.add((j1, j2p))
                nextMoves.add((j1, 0))
                nextMoves.add((0, j2))
                nextMoves.add((min(j1p, j1+j2), max(0, j1p-j1-j2)))
                nextMoves.add((max(0, j2p-j1-j2), min(j2p, j1+j2)))
                
                for move in nextMoves:
                    if move in seen: continue
                    seen.add(move)
                    q.append(move)    
        return False
        
