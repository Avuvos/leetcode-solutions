class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic = {"b": 0, "a": 0, "l": 0, "o": 0, "n": 0}
        for c in text:
            if c in dic:
                dic[c] += 1
        for c in dic:
            if c == "l" or c == "o":
                count = dic[c]
                dic[c] = count // 2
        
        return min(dic.values())
        
