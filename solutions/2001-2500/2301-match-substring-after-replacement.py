class Solution:
    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        dic = {}
        for key, val in mappings:  # turn mappings into dict[char] -> set of replacements
            if key not in dic:
                dic[key] = set()
            dic[key].add(val)

        for index in range(len(s) - len(sub) + 1):  # search if sub can be found from every position
            survived = True
            for j in range(len(sub)):
                if (sub[j] != s[index + j]) and ((sub[j] not in dic) or (s[index + j] not in dic[sub[j]])):
                    survived = False
                    break
            if survived:
                return True
        return False
