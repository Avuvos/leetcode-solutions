class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        answer = []
        
        def dfs(curr, index, s):
            if len(curr) == len(s):
                answer.append(curr)
                return
            
            if s[index].isdigit():
                dfs(curr+s[index], index + 1, s)
            else:
                dfs(curr+s[index].lower(), index + 1, s)
                dfs(curr+s[index].upper(), index + 1, s)
        
        dfs("", 0, s)
        return answer
                
