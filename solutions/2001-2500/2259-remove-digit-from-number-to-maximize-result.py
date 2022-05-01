import collections
import heapq
import math
from typing import List


class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        res = ""
        mx = 0
        for i, c in enumerate(number):
            curr = number[0:i] + number[i + 1:]
            if c == digit and int(curr) > mx:
                mx = int(curr)
                res = curr
        return res
                

