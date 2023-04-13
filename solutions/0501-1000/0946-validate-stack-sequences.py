class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i = j = 0
        stk = []
        while i < len(pushed):
            if not stk or stk[-1] != popped[j]:
                stk.append(pushed[i])
                i += 1
            else:
                j += 1
                stk.pop()
        while j < len(popped):
            if popped[j] == stk[-1]:
                j += 1
                stk.pop()
            else:
                break
        return not stk
