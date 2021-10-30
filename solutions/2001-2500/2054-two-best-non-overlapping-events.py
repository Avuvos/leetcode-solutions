class Solution(object):
    def maxTwoEvents(self, events):
        events = sorted(events, key=lambda x: x[0])
        memo = {}
        def dfs(count, idx):
            if count == 2 or idx >= len(events):
                return 0
            if (count, idx) in memo:
                return memo[(count, idx)]
            take = events[idx][2] + dfs(count + 1, findNextEvent(idx))
            skip = dfs(count, idx + 1)
            memo[(count, idx)] = max(take, skip)
            return max(take, skip)

        def findNextEvent(idx):
            left = idx + 1
            right = len(events) - 1
            while left <= right:
                mid = (left + right)//2
                if events[mid][0] > events[idx][1]:
                    if events[mid - 1][0] > events[idx][1]:
                        right = mid - 1
                    else:
                        return mid
                else:
                    left = mid + 1
            return len(events) + 1
        return dfs(0, 0)
        
