class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
                
        cnt = 0
        for key in d:
            if d[key] % 2 == 0:
                cnt += d[key]
        
        mx_odd = 0
        k = ""
        for key in d:
            if d[key] % 2 == 1 and d[key] > mx_odd:
                mx_odd = d[key]
                k = key
                
        for key in d:
            if d[key] % 2 == 1 and key != k:
                cnt +=  d[key] - 1
                
        return cnt + mx_odd
                
