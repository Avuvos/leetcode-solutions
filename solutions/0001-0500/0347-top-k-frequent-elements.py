class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = Counter(nums)
        return sorted([key for key, value in c.items()], key=lambda x: c[x], reverse=True)[:k]
        
