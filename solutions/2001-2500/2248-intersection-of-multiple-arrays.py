class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        
        return [n for n in range(1001) if all(n in lst for lst in nums)]
