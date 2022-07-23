import bisect
import heapq
import math
import string
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList


class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        st = set()
        counter = 0
        for num in rolls:
            st.add(num)
            if len(st) == k:
                counter += 1
                st = set()
        return counter + 1
            
