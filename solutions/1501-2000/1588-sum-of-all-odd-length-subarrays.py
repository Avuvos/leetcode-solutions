class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        res = 0
        for l in range(1, len(arr) + 1, 2):
            for i in range(0, len(arr)):
                if i + l <= len(arr):
                    res += sum(arr[i : i + l])
        return res
