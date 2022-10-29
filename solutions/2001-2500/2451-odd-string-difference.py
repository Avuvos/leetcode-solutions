from typing import List
class Solution:
    def oddString(self, words: List[str]) -> str:
        lst = []
        for w in words:
            curr = []
            for i in range(0, len(w) - 1):
                curr.append(ord(w[i+1]) - ord(w[i]))
            lst.append((curr, w))

        current = lst[0][0]
        
        one = 0
        cand = -1
        for i in range(1, len(lst)):
            for j in range(len(current)):
                if current[j] != lst[i][0][j]:
                    one += 1
                    cand = i
                    break

        if one == 1:
            return lst[cand][1]
        return lst[0][1]
            
