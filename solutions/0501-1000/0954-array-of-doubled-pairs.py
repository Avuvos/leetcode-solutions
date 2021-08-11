class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        
        cnt = collections.Counter()
        lst = sorted(arr, key=lambda x: abs(x), reverse=True)
        
        for x in lst:
            if cnt[2*x] > 0:
                cnt[2*x] -= 1
            else:
                cnt[x] += 1
                
        return sum(cnt.values()) == 0
