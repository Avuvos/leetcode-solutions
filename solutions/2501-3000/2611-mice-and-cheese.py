class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        both = [(a - b, a, b) for a, b in zip(reward1, reward2)]
        both = sorted(both, reverse=True)
        left = len(reward1)
        ans = 0
        for i, (d, a, b) in enumerate(both):
            if i < k:
                ans += a
            else:
                ans += b
        return ans
        
