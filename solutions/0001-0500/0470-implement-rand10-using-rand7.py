# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        s = 0
        for i in range(10):
            s += rand7()
            
        return 10 if s % 10 == 0 else s % 10
        
        
