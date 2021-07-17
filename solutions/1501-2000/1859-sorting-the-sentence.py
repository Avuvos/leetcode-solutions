class Solution:
    def sortSentence(self, s: str) -> str:
        lst = [0 for i in range(len(s.split()))]

        for word in s.split():
            lst[int(word[len(word)-1])-1] = str(word[0:len(word)-1])
        msg = " ".join(lst)
        return msg
