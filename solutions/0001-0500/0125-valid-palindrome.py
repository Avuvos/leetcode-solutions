class Solution:
    def isPalindrome(self, s: str) -> bool:
        lst = list(filter(lambda x: x.isalnum(), s.lower()))
        return lst == lst[::-1]
