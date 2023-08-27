class Solution:
    def canCross(self, stones: List[int]) -> bool:
        
        stone_to_index = {s : i for i, s in enumerate(stones)}
        
        @cache
        def dfs(index, k):
            if index >= len(stones) - 1:
                return True
            ans = False
            if k - 1 > 0 and (stones[index] + k - 1) in stone_to_index:
                ans |= dfs(stone_to_index[stones[index] + k - 1], k - 1)
                
            if k > 0 and (stones[index] + k) in stone_to_index:
                ans |= dfs(stone_to_index[stones[index] + k], k)
                
            if (stones[index] + k + 1) in stone_to_index:
                ans |= dfs(stone_to_index[stones[index] + k + 1], k + 1)
                
            return ans
        
        return dfs(0, 0)
