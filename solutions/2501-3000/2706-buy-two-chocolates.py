class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        ans = prices[0] + prices[1]
        money -= ans
        if money < 0:
            return money + ans
        return money
