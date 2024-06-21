class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        if minutes == n:
            return sum(customers)
        suffix_sum = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_sum[i] = suffix_sum[i + 1] + customers[i] * (grumpy[i] ^ 1)
        
        ans, prefix_sum, window_sum = 0, 0, 0
        for i in range(minutes):
            window_sum += customers[i]
        ans = window_sum + suffix_sum[minutes];
        
        left = 0
        for right in range(minutes, n):
            window_sum += customers[right]
            window_sum -= customers[left]
            prefix_sum += customers[left] * (grumpy[left] ^ 1)
            left += 1
            ans = max(ans, prefix_sum + window_sum + suffix_sum[right + 1])
        
        return ans
