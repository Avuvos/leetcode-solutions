class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        curr = -1
        lst = s.split()
        for c in lst:
            if c.isdigit():
                if int(c) > curr:
                    curr = int(c)
                else:
                    return False
        return True
