class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        
        def dfs(ind, target, path):
            if len(path) == k and target == 0:
                res.append(path.copy())
                return
            if len(path) >= k or target < 0:
                return
            
            for i in range(ind, 10):
                if n - i >= 0:
                    path.append(i)
                    dfs(i + 1, target - i, path)
                    path.pop()

        dfs(1, n, [])
        return res
