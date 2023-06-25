class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        robots = sorted([(positions[i], healths[i], directions[i], i) for i in range(n)])
        new_health = [x for x in healths]
        ans = []
        INF = 10**9
        stk = []
        for i in range(n):
            p, h, d, index = robots[i]
            if d == 'R':
                stk.append(index)
            else:
                while stk:
                    prev_index = stk[-1]
                    stk.pop()
                    print(f"{prev_index} vs {index}")
                    if new_health[prev_index] < new_health[index]:
                        new_health[index] -= 1
                        new_health[prev_index] = -INF
                        continue
                    if new_health[prev_index] == new_health[index]:
                        new_health[index] = -INF
                        new_health[prev_index] = -INF
                        break
                    #the prev robot is stronger
                    new_health[prev_index] -= 1
                    new_health[index] = -INF
                    stk.append(prev_index)
                    break
        # print(robots)
        # print(new_health)
        for x in new_health:
            if x > -INF:
                ans.append(x)
            
        return ans
        
        
