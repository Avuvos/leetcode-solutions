class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        seen = [False for _ in range(len(arr))]
        def dfs(i):
            if i >= len(arr) or i < 0 or seen[i]:
                return False
            if arr[i] == 0:
                return True
            seen[i] = True
            return dfs(i - arr[i]) or dfs(i + arr[i])
        
        return dfs(start)
