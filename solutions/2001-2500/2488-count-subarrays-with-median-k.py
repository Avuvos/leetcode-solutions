class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        sums=0
        d_left=defaultdict(int)
        d_right=defaultdict(int)
        d_left[0]=1
        d_right[0]=1
        k_idx=-1
        n=len(nums)
        for i in range(n):
            if(nums[i] == k):
                k_idx = i
            elif(nums[i] < k):
                nums[i] = -1
            else: 
                nums[i] = 1
        count=0
        for i in range(k_idx - 1, -1, -1):
            count += nums[i]
            d_left[count] += 1
        count=0
        for i in range(k_idx + 1,n):
            count += nums[i]
            d_right[count] += 1
       
        for key in d_left:
            sums += d_right[-key]*d_left[key]
            sums += d_left[key]*d_right[1-key]
        return sums
            
            
