import bisect
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList
from string import ascii_lowercase
import heapq


class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        alice_month = int(arriveAlice[0:2])
        alice_day = int(arriveAlice[3:])
        bob_month = int(arriveBob[0:2])
        bob_day = int(arriveBob[3:])

        if alice_month == bob_month:
            arrive = (alice_month, alice_day) if alice_day > bob_day else (bob_month, bob_day)
        else:
            arrive = (alice_month, alice_day) if alice_month > bob_month else (bob_month, bob_day)

        alice_month = int(leaveAlice[0:2])
        alice_day = int(leaveAlice[3:])
        bob_month = int(leaveBob[0:2])
        bob_day = int(leaveBob[3:])

        if alice_month == bob_month:
            leave = (alice_month, alice_day) if alice_day < bob_day else (bob_month, bob_day)
        else:
            leave = (alice_month, alice_day) if alice_month < bob_month else (bob_month, bob_day)

        res = 0
        for m in range(arrive[0], leave[0] + 1):
            current_days = days[m - 1]
            if m == arrive[0]:
                current_days -= arrive[1] - 1
            if m == leave[0]:
                current_days -= days[m - 1] - leave[1]
            res += current_days
        return max(res, 0)
