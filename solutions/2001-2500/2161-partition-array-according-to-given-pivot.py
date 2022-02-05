class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        lt, eq, gt = 0, 0, 0
        for n in nums:
            if n < pivot:
                lt += 1
            elif n > pivot:
                gt += 1
            else:
                eq += 1
        first_pos = 0
        second_pos = lt
        third_pos = lt + eq

        res = [0 for _ in range(len(nums))]
        for n in nums:
            if n < pivot:
                res[first_pos] = n
                first_pos += 1
            elif n > pivot:
                res[third_pos] = n
                third_pos += 1
            else:
                res[second_pos] = n
                second_pos += 1
        nums = res
        return nums
