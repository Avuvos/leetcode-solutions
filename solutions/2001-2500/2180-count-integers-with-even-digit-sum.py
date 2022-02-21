class Solution:
    def countEven(self, num: int) -> int:
        
        def sum_digits(n):
            s = 0
            while n > 0:
                s += n % 10
                n = n // 10
            return s
        
        res = 0
        
        for i in range(2, num + 1):
            if sum_digits(i) % 2 == 0:
                res += 1
        
        return res
            
