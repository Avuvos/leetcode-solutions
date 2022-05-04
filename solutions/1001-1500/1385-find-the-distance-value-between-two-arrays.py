class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        d_val = 0
        arr2 = sorted(arr2)
        for i in range(0, len(arr1)):
            ok = True
            for j in range(0, len(arr2)):
                if abs(arr1[i]-arr2[j]) <= d:
                    ok = False
            if ok:
                d_val += 1
                
        return d_val
