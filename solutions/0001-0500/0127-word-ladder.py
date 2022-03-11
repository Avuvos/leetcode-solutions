class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        wordList = set(wordList)
        wordList.add(beginWord)
        
        q = deque([beginWord])
        res = 0
        
        while q:
            size = len(q)
            for i in range(size):
                word = q.popleft()
                if word == endWord:
                    return res + 1
                if word not in wordList:
                    continue
                wordList.remove(word)
                for j in range(len(word)):
                    f = word[0:j]
                    l = word[j+1:]
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        st = f + c + l
                        if c != word[j] and st in wordList:
                            q.append(st)
            res += 1
            
        return 0
        
        
