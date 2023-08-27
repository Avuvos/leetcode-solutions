class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        
        #if this is not met, then for sure we cannot make it
        if sum(nums) < target:
            return -1
        
        #set up a counter for each power of two available
        LOG = 32
        cnt = [0] * (LOG + 5)
        for x in nums:
            cnt[int(math.log2(x))] += 1
        
        bit = ans = 0
        #form the answer bit by bit
        while bit < LOG:
            advance = True
            
            #we need the current bit
            if (target >> bit) & 1:
                
                #find the first power of two that we can divide by and get the bit
                while cnt[bit] == 0:
                    advance = False
                    bit += 1
                    ans += 1
                
                #decrease its count by one since we just used it
                cnt[bit] -= 1
                
            #propagate the remaining ones forward to be used later
            if advance:
                cnt[bit + 1] += cnt[bit] // 2
                bit += 1
                
        return ans
                
        
            
            
                
