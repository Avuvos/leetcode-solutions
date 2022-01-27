class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        res = []
        dic = Counter(nums)
        
        for key in dic:
            if dic[key] == 1 and key + 1 not in dic and key - 1 not in dic:
                res.append(key)
        
        return res
