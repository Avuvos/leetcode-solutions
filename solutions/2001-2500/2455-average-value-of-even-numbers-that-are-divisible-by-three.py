class Solution:
    def averageValue(self, nums: List[int]) -> int:
        lst = [x for x in nums if x % 6 == 0]
        if len(lst) > 0:
            return sum(lst)//len(lst)
        return 0
