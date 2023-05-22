class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        
        @cache
        def dfs(i, cnt):
            if i >= len(special):
                return sum([p * x for p, x in zip(price, cnt)])
            times = 0
            res = 10**18
            while True:
                nxt = [x - times*p for p, x in zip(special[i], cnt)]
                if all(x >= 0 for x in nxt):
                    res = min(res, special[i][-1]*times + dfs(i + 1, tuple([x - times*p for p, x in zip(special[i], cnt)])))
                    times += 1
                else:
                    break
            return res
        return dfs(0, tuple([x for x in needs]))
