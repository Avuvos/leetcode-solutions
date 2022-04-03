class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        res = [[], []]
        
        d = {}
        for w, l in matches:
            if w not in d:
                d[w] = 0
            if l not in d:
                d[l] = 0
            d[l] += 1
        
        for player, loses in d.items():
            if loses == 1:
                res[1].append(player)
            elif loses == 0:
                res[0].append(player)
                
        res[0].sort()
        res[1].sort()
        return res
            
        
