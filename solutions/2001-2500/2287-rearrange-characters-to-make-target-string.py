class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        c_target = Counter(target)
        c_str = Counter(s)
        for key in c_target:
            if key not in c_str or c_str[key] < c_target[key]:
                return 0
            c_str[key] = c_str[key] // c_target[key]

        res = float('inf')
        for key in c_str:
            if key in c_target:
                res = min(res, c_str[key])
        return res
