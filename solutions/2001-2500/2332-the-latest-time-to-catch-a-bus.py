class Solution:
    def latestTimeCatchTheBus(self, buses: List[int], pas: List[int], capacity: int) -> int:
        #there are two cases, either we get on the bus before some person
        #got to it, or we get on the bus when it leaves, update res.
        buses.sort()
        pas.sort()
        p = res = 0
        pas_set = set(pas)
        for bus in buses:
            currCap = 0
            while p < len(pas) and pas[p] <= bus and currCap < capacity:
                if pas[p] - 1 not in pas_set:
                    res = pas[p] - 1
                p += 1
                currCap += 1
            if currCap < capacity and bus not in pas_set:
                res = bus
        return res              
