class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        res = 0
        for st in operations:
            if st[1] == "+":
                res += 1
            else:
                res -= 1            
        return res
