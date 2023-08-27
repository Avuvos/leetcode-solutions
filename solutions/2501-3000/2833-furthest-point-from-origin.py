class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        delta = 0
        extra = 0
        for x in moves:
            if x == 'L':
                delta += 1
            elif x == 'R':
                delta -= 1
            else:
                extra += 1
        
        return abs(delta) + extra
            
