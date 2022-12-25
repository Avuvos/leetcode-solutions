class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        ps = [[0, 0, 0]]
        suf = [[0, 0, 0]]
        for i, c in enumerate(s):
            ps.append(ps[-1].copy())
            if c == 'a':
                ps[i + 1][0] += 1
            elif c == 'b':
                ps[i + 1][1] += 1
            else:
                ps[i + 1][2] += 1
        
        for i in range(n - 1, -1, -1):
            suf.append(suf[-1].copy())
            c = s[i]
            if c == 'a':
                suf[-1][0] += 1
            elif c == 'b':
                suf[-1][1] += 1
            else:
                suf[-1][2] += 1
        suf.reverse()
        #print(ps)
        #print(suf)
        if ps[-1][0] < k or ps[-1][1] < k or ps[-1][2] < k:
            return -1
        if k == 0:
            return 0
        
        def good(m):
            for i in range(m + 1):
                if ps[i][0] + suf[n - m + i][0] >= k and ps[i][1] + suf[n - m + i][1] >= k and ps[i][2] + suf[n - m + i][2] >= k:
                    return True
            return False
        res = n
        left = 1
        right = n
        while left <= right:
            mid = (left + right)//2
            if good(mid):
                right = mid - 1
                res = mid
            else:
                left = mid + 1
        return res
                
