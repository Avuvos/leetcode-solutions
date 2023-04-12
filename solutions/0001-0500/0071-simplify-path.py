class Solution:
    def simplifyPath(self, path: str) -> str:
        lst = path.split('/')
        res = []
        for w in lst:
            if res and w == '..':
                res.pop()
            elif len(w) > 0 and w != '.' and w != '..':
                res.append(w)
        return '/' + '/'.join(res)
            
