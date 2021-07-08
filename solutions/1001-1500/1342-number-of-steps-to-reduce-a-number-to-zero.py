class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0
        c=1
        while num != 1:
            if num%2==0:
                num = num//2
            else:
                num -= 1
            c += 1
        return c
