class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n=len(nums)
        lst = [0 for i in range(0, 2*n)]
        for i in range(n):
            lst[i] = nums[i]
            lst[i+n] = nums[i]
        return lst
        
