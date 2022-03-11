class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        seen = set()
        q = deque(["0000"])
        res = 0
        
        while q:
            size = len(q)
            for i in range(size):
                st = q.popleft()
                if st == target:
                    return res
                if st in deadends or st in seen:
                    continue
                seen.add(st)
                for j in range(4):
                    f = st[0:j]
                    l = st[j+1:]
                    currNum = int(st[j])
                    if currNum == 9:
                        q.append(f + "0" + l)
                        q.append(f + "8" + l)
                    elif currNum == 0:
                        q.append(f + "9" + l)
                        q.append(f + "1" + l)
                    else:
                        q.append(f + str(currNum + 1) + l)
                        q.append(f + str(currNum - 1) + l)
            res += 1
            
        return -1
                    
