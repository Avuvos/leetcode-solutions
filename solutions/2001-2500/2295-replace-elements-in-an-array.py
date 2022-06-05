class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        hashMap = {x : i for i, x in enumerate(nums)}
        
        for a, b in operations: #swap a with b
            index = hashMap[a]
            nums[index] = b
            hashMap[b] = index
        
        return nums
