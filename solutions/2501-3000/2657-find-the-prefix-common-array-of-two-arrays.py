class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        sa = set()
        sb = set()
        both = set()
        ans = []
        for i in range(len(A)):
            a = A[i]
            b = B[i]
            both.add(a)
            both.add(b)
            sa.add(a)
            sb.add(b)
            current = 0
            for num in both:
                if num in sa and num in sb:
                    current += 1
            ans.append(current)
        return ans
