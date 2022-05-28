class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        words = []
        dic = {}
        for m, sender in zip(messages, senders):
            if sender not in dic:
                dic[sender] = 0
            dic[sender] += len(m.split(" "))
        sorted_dic = sorted([(dic[s], s) for s in dic], reverse=True)
        return sorted_dic[0][1]
