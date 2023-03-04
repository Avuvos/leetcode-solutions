class Solution:
    def splitNum(self, num: int) -> int:
        s = [x for x in str(num)]
        s.sort()
        num1 = num2 = 0
        flag = True
        for i in range(len(s)):
            if flag:
                num1 *= 10
                num1 += int(s[i])
            else:
                num2 *= 10
                num2 += int(s[i])
            flag = not flag
        return num1 + num2
            
