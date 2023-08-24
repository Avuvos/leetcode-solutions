class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        width = 0
        line = []
        
        for word in words:
            if len(word) + width + len(line) <= maxWidth:
                width += len(word)
                line.append(word)
                continue
            if len(line) == 1:
                ans.append("{0: <{width}}".format( " ".join(line), width=maxWidth))
            else:
                space = (maxWidth - width) // (len(line) - 1)
                extra = (maxWidth - width) % (len(line) - 1)
                index = 0
                while extra:
                    line[index] += " "
                    extra -= 1
                    index += 1
                ans.append((" " * space).join(line))
            line = [word]
            width = len(word)
        
        ans.append("{0: <{width}}".format(" ".join(line), width=maxWidth))
        return ans
