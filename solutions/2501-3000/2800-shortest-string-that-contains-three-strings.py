class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        
        #concat x to y
        def concat(y, x):
            if x in y:
                return y
            for i in range(len(x), 0, -1):
                if i > len(y): continue
                if x[0:i] == y[len(y)-i:]:
                    return y + x[i:]
            return y + x
    
        l = [a, b, c]
        cands = []
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    if i == j or j == k or k == i: continue
                    cands.append(concat(concat(l[i], l[j]), l[k]))
        
        cands.sort(key = lambda x: (len(x), x)) #min length then min lex
        return cands[0]
        
        
