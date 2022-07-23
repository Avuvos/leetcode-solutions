import bisect
import heapq
import math
import string
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import sortedlist, SortedList


class NumberContainers:

    def __init__(self):
        self.idx_to_num = {}
        self.num_to_list_idx = {}

    def change(self, index: int, number: int) -> None:
        if number not in self.num_to_list_idx:
            self.num_to_list_idx[number] = SortedList([])
        if index in self.idx_to_num:
            to_del_num = self.idx_to_num[index]
            cur_lst = self.num_to_list_idx[to_del_num]
            cur_lst.discard(index)
        self.num_to_list_idx[number].add(index)
        self.idx_to_num[index] = number


    def find(self, number: int) -> int:
        if number not in self.num_to_list_idx or not self.num_to_list_idx[number]:
            return -1
        return self.num_to_list_idx[number][0]
