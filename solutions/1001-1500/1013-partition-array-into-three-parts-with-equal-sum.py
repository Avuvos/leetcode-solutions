class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        s = sum(arr)
        if s % 3 != 0:
            return False
        req = s // 3
        partSum = cnt = 0
        for n in arr:
            partSum += n
            if partSum == req:
                partSum = 0
                cnt += 1
        return cnt >= 3 
        
        
