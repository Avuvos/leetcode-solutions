class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        n = len(people)
        m = len(req_skills)
        
        skill_idx = {s : i for i, s in enumerate(req_skills)}
        
        cand = []
        for skills in people: 
            val = 0
            for skill in skills: 
                val |= 1 << skill_idx[skill] 
            cand.append(val)
        
        @cache
        def dfs(index, mask):
            if mask == 0:
                return []
            if index >= n:
                return [0] * 80
            if not (mask & cand[index]):
                return dfs(index + 1, mask)
            skip = dfs(index + 1, mask)
            take = [index] + dfs(index + 1, mask & ~cand[index])
            return min(take, skip, key=len)
        
        return dfs(0, ((1 << m) - 1))
