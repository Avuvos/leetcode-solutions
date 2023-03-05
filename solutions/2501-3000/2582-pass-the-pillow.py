class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        ans = 1
        left = False
        for i in range(time):
            if left:
                ans -= 1
            else:
                ans += 1
            if ans == n:
                left = True
            if ans == 1:
                left = False
        return ans
