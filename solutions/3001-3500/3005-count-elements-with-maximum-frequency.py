class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        return sum([val for key, val in Counter(nums).items() if val == max(Counter(nums).values())])
