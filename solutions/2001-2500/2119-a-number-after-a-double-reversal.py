class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        if num == 0: return True
        rev = (str(num))[::-1]
        new_st = ""
        for i in range(len(rev)):
            if rev[i] != "0" or len(new_st) >= 1:
                new_st += rev[i]
                
        return new_st[::-1] == str(num)
                
        
