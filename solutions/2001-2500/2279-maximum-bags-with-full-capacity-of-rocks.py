class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        capacityRocksDelta = [(c, r, c - r) for c, r in zip(capacity, rocks)]
        capacityRocksDelta.sort(key=lambda x: x[2])
        res = 0
        for c, r, delta in capacityRocksDelta:
            if additionalRocks >= delta:
                additionalRocks -= delta
                res += 1
            else:
                break
        return res
