class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
            memo = {}
            rides = sorted(rides, key=lambda x: x[0])
            def dfs(i):
                if i >= len(rides) or rides[i][0] >= n:
                    return 0
                if i in memo:
                    return memo[i]

                take = rides[i][1] - rides[i][0] + rides[i][2] + dfs(findNext(i))
                skip = dfs(i+1)
                memo[i] = max(take, skip)
                return memo[i]

            def findNext(index):
                left = index + 1
                right = len(rides) - 1
                while left <= right:
                    mid = (left+right)//2
                    if rides[mid][0] >= rides[index][1]:
                        if  rides[mid-1][0] >= rides[index][1]:
                            right = mid - 1
                        else:
                            return mid
                    else:
                        left = mid + 1
                return len(rides) + 1
                

            return dfs(0)
