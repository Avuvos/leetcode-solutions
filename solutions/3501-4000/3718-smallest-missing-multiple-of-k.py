class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        s = set(nums)
        i = 1
        while True:
            if i * k not in s:
                return i * k
            i += 1
        return -1
