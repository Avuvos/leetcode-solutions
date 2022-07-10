class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if start.count('L') != target.count('L') or start.count('R') != target.count('R'):
            return False
        
        left = [i for i, c in enumerate(target) if c == 'L']
        right = [i for i, c in enumerate(target) if c == 'R']
       
        l = r = 0 #pointers to keep track of the current closest right and left target, if cant reach return false
        for i, c in enumerate(start):
            if c == 'L':
                if (r >= len(right) or (right[r] > i and right[r] > left[l])) and i >= left[l]:
                    l += 1
                else:
                    return False
            elif c == 'R':
                if (l >= len(left) or (left[l] > i and left[l] > right[r])) and i <= right[r]:
                    r += 1
                else:
                    return False
        return True
                
        
