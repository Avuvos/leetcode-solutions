class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        res = [float('inf')]

        def calc_time(lst):
            if len(lst) == 0:
                return 0
            if len(lst) == 1:
                return lst[0]
            if len(lst) == 2:
                lst = [0] + [0] + lst
            if len(lst) == 3:
                lst = [0] + lst
            return (lst[0]*10 + lst[1])*60 + (lst[2]*10 + lst[3])

        visited = set()
        cost = []
        
        def dfs(dig, lst):
            if calc_time(lst) == targetSeconds:
                res[0] = min(res[0], sum(cost))
            if len(lst) >= 4:
                return
            
            num = ""
            for n in lst:
                num += str(n)
            if (num, dig) in visited:
                return
            visited.add((num, dig))
            
            cost.append(pushCost)
            dfs(dig, lst + [dig])
            cost.pop()
            
            for i in range(0, 10):
                if i != dig:
                    cost.append(moveCost)
                    cost.append(pushCost)
                    dfs(i , lst + [i])
                    cost.pop()
                    cost.pop()

        dfs(startAt, [])
        return res[0]

