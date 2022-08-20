class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        
        stations.sort()
        heap = []
        pos = startFuel
        index = 0
        res = 0
        
        while index < len(stations):
            while index < len(stations) and pos >= stations[index][0]:
                heapq.heappush(heap, -stations[index][1])
                index += 1
            if pos >= target:
                return res
            elif not heap:
                return -1
            else:
                pos += -(heapq.heappop(heap))
                res += 1
        
        while pos < target and heap:
            pos += -(heapq.heappop(heap))
            res += 1
            

        return res if pos >= target else -1
