class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for w in words:
            ans += w.split(separator)
        
        return [w for w in ans if len(w) > 0]
