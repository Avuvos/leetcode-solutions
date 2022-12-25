class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        
        
        def good(d):
            num = price[0]
            cnt = 1
            index = 1
            while index < len(price) and cnt < k:
                if price[index] - num >= d:
                    num = price[index]
                    cnt += 1
                index += 1
            return cnt >= k
                
        left, right = 0, max(price) + 17
        res = 0
        while left <= right:
            mid = (left + right)//2
            if good(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res
