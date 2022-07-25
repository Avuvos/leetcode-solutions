from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def repeatedCharacter(self, s: str) -> str:
        st = set()
        for x in s:
            if x in st:
                return x
            st.add(x)
        return None
