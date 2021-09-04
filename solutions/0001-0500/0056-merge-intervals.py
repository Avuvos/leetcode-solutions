class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        if n == 1:
            return intervals
        
        intervals = sorted(intervals, key=lambda x: x[0]) #sort by starting times
        res = []
        i = 0
        
        while (i < n):
            left = intervals[i][0]
            right = intervals[i][1]
            curr = [left, right] #curr interval
            while (i+1 < n): #here we check for merges
                nextLeft = intervals[i+1][0]
                nextRight = intervals[i+1][1]
                if nextRight <= right and nextLeft >= left: #if im already between,skip
                    i += 1
                elif right >= nextLeft: #merge
                    curr[1] = nextRight
                    right = nextRight
                    i += 1
                else: #no overlap
                    break
            res.append(curr)
            i += 1
        return res
