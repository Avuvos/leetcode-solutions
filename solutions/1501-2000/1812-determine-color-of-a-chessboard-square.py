class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        odd = ['a', 'c', 'e', 'g']
        even = ['b', 'd', 'f', 'h']
        
        letter = coordinates[0]
        digit = int(coordinates[1])
        
        return digit%2 ==0 and letter in odd or digit%2==1 and letter in even
