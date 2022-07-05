class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        if n == 1: return 1

        dic = {} #dic[i] is the length of the sequence using i
        for num in nums:
            if num in dic:
                continue
            l = dic.get(num - 1, 0)
            r = dic.get(num + 1, 0)
            length = l + r + 1
            dic[num] = length
            dic[num - l] = length
            dic[num + r] = length
        return max(dic.values())
