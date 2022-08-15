class Solution:
    def smallestNumber(self, pattern: str) -> str:
        
        def notValid(c, st, pat):
            if len(st) > 0 and c < int(st[-1]) and pat == 'I':
                return True
            elif len(st) > 0 and c > int(st[-1]) and pat == 'D':
                return True
            return False
        
        res = "9999999999"
        def dfs(index, curr_str):
            nonlocal res
            if index >= len(pattern):
                res = min(res, curr_str)
                return
            for digit in range(1, 10):
                if str(digit) not in curr_str:
                    if notValid(digit, curr_str, pattern[index]):
                        continue
                    dfs(index + 1, curr_str + str(digit))
                    
        for digit in range(1, 10):
            dfs(0, str(digit))
        return res




