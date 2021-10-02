class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        
        def dfs(cand, target, path , i):
            if target == 0:
                answer.append(path)
            elif target < 0 or i == len(cand):
                return None
            else: #means target>0 and we have somethin in cand
                dfs(cand, target-cand[i], path+[cand[i]], i) #use it
                dfs(cand, target, path, i+1) #skip it
            
        dfs(candidates, target, [] , 0)
        return answer
