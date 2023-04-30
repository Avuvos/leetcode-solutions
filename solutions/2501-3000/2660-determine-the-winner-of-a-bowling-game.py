class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        scoreA = scoreB = 0
        for i, a in enumerate(player1):
            if i - 1 >= 0 and player1[i - 1] == 10 or i - 2 >= 0 and player1[i - 2] == 10:
                scoreA += 2*a
            else:
                scoreA += a
        for i, a in enumerate(player2):
            if i - 1 >= 0 and player2[i - 1] == 10 or i - 2 >= 0 and player2[i - 2] == 10:
                scoreB += 2*a
            else:
                scoreB += a
        
        if scoreA > scoreB:
            return 1
        elif scoreA < scoreB:
            return 2
        else:
            return 0
