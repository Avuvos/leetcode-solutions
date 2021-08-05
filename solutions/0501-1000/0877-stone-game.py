class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        
        piles = sorted(piles, reverse=True)
        a = 0
        b = 0
        
        for i in range(len(piles)):
            if i%2 == 0:
                a += piles[i]
            else:
                b += piles[i]

        if a > b:
            return True
        else:
            return False
