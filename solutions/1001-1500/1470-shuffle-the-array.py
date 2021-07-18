class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        L =[]
        for i in range(0,len(nums)-n):
            L.append(nums[i])
            L.append(nums[n+i])
        return L
