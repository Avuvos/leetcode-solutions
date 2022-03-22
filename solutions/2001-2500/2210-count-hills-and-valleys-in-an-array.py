class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        uniq = []
        uniq.append(nums[0])
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                uniq.append(nums[i])
        
        res = 0
        for i in range(1, len(uniq) - 1):
            if uniq[i] > uniq[i - 1] and uniq[i] > uniq[i + 1]:
                res += 1
            elif uniq[i] < uniq[i - 1] and uniq[i] < uniq[i + 1]:
                res += 1
        return res
