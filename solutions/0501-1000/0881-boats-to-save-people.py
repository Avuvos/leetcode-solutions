class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        right = len(people) - 1
        left = 0
        ans = 0
        while left <= right:
            if left == right: 
                ans += 1
                break
            if people[right] + people[left] <= limit:
                left += 1
            right -= 1
            ans += 1
        return ans
