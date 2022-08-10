from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList


class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        grades.sort()
        groups = [[grades[0], 1]]
        groups_index = 0
        for i in range(1, len(grades)):
            if groups[groups_index][1] == groups_index + 1:
                groups.append([grades[i], 1])
                groups_index += 1
            else:
                groups[groups_index][1] += 1
                groups[groups_index][0] += grades[i]
        if groups[-1][1] != len(groups):
            return len(groups) - 1
        return len(groups)


