class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10 ** 9 + 7
        binN = bin(n)[2::]
        binN = binN[::-1]
        powers = []
        for i in range(len(binN)):
            if binN[i] == '1':
                powers.append(2 ** i)
        prefix = [1] * (len(powers) + 1)
        for i, p in enumerate(powers):
            prefix[i + 1] = prefix[i] * powers[i]

        res = []
        for l, r in queries:
            ans = prefix[r + 1] // prefix[l]
            ans %= mod
            res.append(ans)
        return res
