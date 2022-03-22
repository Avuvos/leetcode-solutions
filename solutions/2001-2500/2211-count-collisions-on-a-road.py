class Solution:
    def countCollisions(self, d: str) -> int:
        a = 0
        while a < len(d) and d[a] == "L":
            a += 1
        b = len(d) - 1
        while b >= 0 and d[b] == "R":
            b -= 1
            
        res = 0
        while a <= b:
            if d[a] != "S":
                res += 1
            a += 1
        return res
        
