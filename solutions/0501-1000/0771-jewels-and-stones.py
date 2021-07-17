class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return len([1 for char in stones if char in jewels])
   
