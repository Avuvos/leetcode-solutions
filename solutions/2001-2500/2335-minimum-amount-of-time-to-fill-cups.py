class Solution:
    def fillCups(self, amount: List[int]) -> int:
        print('----')
        a, b, c = 0, 1, 2
        time = 0
        while amount[a] > 0 or amount[b] > 0 or amount[c] > 0:
            i = j = 0
            if amount[a] > amount[b] and amount[a] > amount[c]:
                i = 0
                if amount[b] > amount[c]:
                    j = 1
                else:
                    j = 2
            elif amount[b] > amount[c]:
                i = 1
                if amount[a] > amount[c]:
                    j = 0
                else:
                    j = 2
            else:
                i = 2
                if amount[a] > amount[b]:
                    j = 0
                else:
                    j = 1
            amount[i] -= 1
            amount[j] -= 1
            time += 1
        return time
