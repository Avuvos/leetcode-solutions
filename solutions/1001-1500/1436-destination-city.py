class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        seen = set()
        res = ""
        for path in paths:
            seen.add(path[0])
            
        for path in paths:
            if path[1] not in seen:
                res = path[1]
                break
            
        return res
