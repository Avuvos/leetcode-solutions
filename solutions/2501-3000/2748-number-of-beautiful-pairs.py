class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if (gcd(int(str(nums[i])[0]), nums[j] % 10) == 1):
                    ans += 1
        return ans
