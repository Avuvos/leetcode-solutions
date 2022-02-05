class Solution:
    def minimumSum(self, num: int) -> int:
        num2 = str(num)
        n = len(num2)
        num2 = "".join(sorted(num2))
        new1 = int(num2[0])*10 + int(num2[2])
        new2 = int(num2[1])*10 + int(num2[3])

        return new1 + new2
