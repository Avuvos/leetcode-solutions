import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        res = 0
        s = str(num)
        for i in range(0, len(s)):
            #print(int(s[i:i + k]))
            #print(i + k < len(s))
            if i + k <= len(s) and int(s[i:i + k]) !=0 and num % int(s[i:i + k]) == 0:
                res += 1
        return res

