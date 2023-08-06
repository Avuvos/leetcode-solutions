class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        #binary search the amt of uniq items to pick.
        #lets say we picked x uniq items (x <= k)
        #pick the top x
        #then fill with k - x best ones that are left.
        #the binary search here is the "pisga problem"
        #if f(mid) > f(mid - 1) we go left, otherwise go right, always update the answer
        
        items.sort(reverse=True)
        
        def f(x):
            total = 0
            y = k - x
            seen = set()
            seen_idx = set()
            
            for index, (prof, cat) in enumerate(items):
                if x <= 0: break
                if cat in seen: continue
                seen.add(cat)
                seen_idx.add(index)
                x -= 1
                total += prof
            
            for index, (prof, cat) in enumerate(items):
                if y <= 0: break
                if index in seen_idx: continue
                if cat not in seen: continue
                y -= 1
                total += prof
               
            return total + len(seen) ** 2
            
            
        left = 0
        right = k
        while left <= right:
            mid = left + (right - left)//2
            if f(mid) >= f(mid - 1):
                ans = f(mid)
                left = mid + 1
            else:
                ans = f(mid - 1)
                right = mid - 1
        
        return ans
    
