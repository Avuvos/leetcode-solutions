class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key = lambda x: x[1])
        q2 = sorted([(q, i) for i, q in enumerate(queries)])
        ans = len(q2) * [0]
        cnt = (n + 1) * [0]
        
        p = 0
        left = 0
        s = 0
        for time, index in q2:
            while p < len(logs) and logs[p][1] <= time:
                cnt[logs[p][0]] += 1
                if cnt[logs[p][0]] == 1:
                    s += 1
                p += 1
            
            while left < len(logs) and logs[left][1] < time - x:
                cnt[logs[left][0]] -= 1
                if cnt[logs[left][0]] == 0:
                    s -= 1
                left += 1
            
            ans[index] = n - s
            
        return ans
            
            
        
