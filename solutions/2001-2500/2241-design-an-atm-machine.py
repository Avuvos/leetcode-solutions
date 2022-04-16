import collections
import heapq
from typing import List


class ATM:

    def __init__(self):
        self.money = [0] * 5
        self.coins = [20, 50, 100, 200, 500]
        
    def deposit(self, banknotesCount: List[int]) -> None:
        for idx, c in enumerate(banknotesCount):
            self.money[idx] += c

    def withdraw(self, amount: int) -> List[int]:
        curr = [c for c in self.money]
        res = [0] * 5
        for idx in range(4, -1, -1):
            if amount == 0: break
            
            cnt = curr[idx]
            coin = self.coins[idx]
            
            use = min(cnt, amount // coin)
        
            res[idx] = use
            curr[idx] -= use
            amount -= coin * use

                
        if amount == 0:
            self.money = [c for c in curr]
            return res
        
        return [-1]
# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
