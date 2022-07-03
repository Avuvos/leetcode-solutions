class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        res = ""
        ab = "abcdefghijklmnopqrstuvwxyz"
        dic = {}
        ptr = 0
        for i in range(len(key)):
            if key[i] == " ": continue
            if key[i] not in dic:
                dic[key[i]] = ab[ptr]
                ptr += 1
        
        for c in message:
            if c == " ":
                res += c
            else:
                res += dic[c]
        return res
