class Solution:
    
    def countAnagrams(self, s: str) -> int:
        def find_inverse(x, mod):
            if x == 1: return 1
            return mod - ((mod//x) * find_inverse(mod%x, mod)) % mod
        n = len(s)
        MOD = 10**9 + 7
        fact = [1, 1]
        for i in range(2, n + 1):
            fact.append(fact[-1] * i)
            fact[i] %= MOD
            if fact[i] < 0:
                fact[i] += MOD
        res = 1
        for word in s.split(" "):
            counter = [0] * 26
            for c in word:
                counter[ord(c) - ord('a')] += 1
            word_res = fact[len(word)]
            to_div = 1
            for amt in counter:
                to_div = to_div * (fact[amt])
                to_div %= MOD
                if to_div < 0: to_div += MOD
            
            to_div_inv = find_inverse(to_div, MOD)
            word_res *= to_div_inv
            res *= word_res
            res %= MOD
            if res < 0: res += MOD
        return res
