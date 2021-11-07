class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        res = 0
        vowels = "aeiou"
        n = len(word)
        for i in range(n):
            s = set()
            for j in range(i, n):
                if word[j] in vowels:
                    s.add(word[j])
                    if len(s) == 5:
                        res += 1
                else:
                    break
        return res
