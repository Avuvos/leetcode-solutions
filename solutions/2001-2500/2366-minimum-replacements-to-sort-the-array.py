class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        prev = nums[-1]
        
        for i in range(n - 2, - 1, -1):
            x = nums[i]
            k = (x + prev - 1) // prev
            ans += k - 1
            prev = x // k
            
        return ans
