class Solution:
    def maxProduct(self, words: List[str]) -> int:
        lst = []
        N = len(words)
        for word in words:
            st = set()
            for c in word:
                st.add(c)
            lst.append(st)
        
        res = 0
        for i in range(N):
            st1 = lst[i]
            for j in range(i + 1, N):
                st2 = lst[j]
                if len(st1) + len(st2) == len(st1.union(st2)):
                    res = max(res, len(words[i]) * len(words[j]))
        return res
