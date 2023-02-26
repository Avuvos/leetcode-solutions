class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [0] * n
        right = [0] * n
        for i in range(1, n):
            left[i] = left[i - 1] + nums[i - 1]
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] + nums[i + 1]
        
        return [abs(a-b) for (a, b) in zip(left, right)]
