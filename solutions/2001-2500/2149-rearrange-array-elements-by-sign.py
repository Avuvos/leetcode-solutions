class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = 0 
        neg = 0
        post = []
        negt = []
        
        for x in nums:
            if x > 0:
                post.append(x)
            else:
                negt.append(x)
                
        for i in range(len(nums)):
            if i % 2 == 0:
                nums[i] = post[pos]
                pos += 1
            else:
                nums[i] = negt[neg]
                neg += 1
        return nums
        
                
