class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        
        n = target
        
        steps = 0
        while n != 1:
            if maxDoubles == 0:
                return steps + n - 1
            if n % 2 == 0 and maxDoubles > 0:
                maxDoubles -= 1
                n = n // 2
            else:
                n -= 1
            steps += 1
            
        return steps
            
