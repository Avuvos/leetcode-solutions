class Solution:
    def addMinimum(self, word: str) -> int:
        i = 0
        n = len(word)
        ans = 0
        used = [False for _ in range(n + 1)]
        while i < n:
            if used[i]:
                i += 1
                continue
            if word[i] == 'a':
                if i + 1 < n and word[i + 1] == 'b':
                    used[i + 1] = True
                if i + 1 >= n or word[i + 1] != 'b':
                    ans += 1
                    if i + 1 >= n or word[i + 1] != 'c':
                        ans += 1
                    elif i + 1 < n and word[i + 1] == 'c':
                        used[i + 1] = True
                elif i + 2 >= n or word[i + 2] != 'c':
                    ans += 1
                else:
                    used[i + 2] = True
            elif word[i] == 'b':
                ans += 1
                if i + 1 >= n or word[i + 1] != 'c':
                    ans += 1
                else:
                    used[i + 1] = True
            elif word[i] == 'c':
                ans += 2
            i += 1
        return ans
