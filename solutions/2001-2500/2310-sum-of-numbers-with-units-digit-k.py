class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        # check if there is a t such that t * k === num mod 10
        for t in range(1, num + 1):
            if t * k % 10 == num % 10 and t*k <= num:
                return t
        return -1
