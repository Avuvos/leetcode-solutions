class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        
        def changeNum(num):
            digitSumSquared = 0
            while num > 0:
                digitSumSquared += (num % 10)**2
                num = num // 10 
            return digitSumSquared
        
        while n != 1:
            if n in s:
                return False
            s.add(n)
            n = changeNum(n)
            
        return True
