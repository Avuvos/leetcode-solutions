class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        #some binary number + num2 * the number of bits of that binary number = nums1
        #so we want num1 - num2*k = b
        #if we fix k, the question becomes can we get the number b with k bits?
        
        if num2 > num1:
            return -1
        
        for k in range(1, 62):
            b = num1 - num2*k
            if b <= 0:
                break
            if b.bit_count() <= k and k <= b:
                return k
        
        return -1
        
