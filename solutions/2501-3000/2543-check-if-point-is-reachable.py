class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        x = targetX
        y = targetY
        while x % 2 == 0:
            #print(x)
            x = x // 2
        while y % 2 == 0:
            #print(y)
            y = y //2
        if x == 1 or y == 1:
            return True
        while y > 0 and x > 0:
            #print(x, y)
            if y >= x:
                y -= x
            else:
                x -= y
            if x == 1 or y == 1:
                return True
            if x % 2 == 0:
                x = x//2
            if y % 2 == 0:
                y = y//2
        return False
