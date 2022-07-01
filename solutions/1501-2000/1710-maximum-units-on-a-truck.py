class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x: x[1], reverse=True)
        ans = 0
        for n, u in boxTypes:
            if n <= truckSize:
                ans += n*u
                truckSize -= n
            else:
                ans += truckSize*u
                break
        return ans
