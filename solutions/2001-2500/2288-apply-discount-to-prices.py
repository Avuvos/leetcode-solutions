class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        s = sentence.split()
        for index, word in enumerate(s):
            if word[0] != '$' or not word[1:].isnumeric():
                continue
            curr_price = int(word[1:])
            new_price = curr_price - curr_price*(discount/100)
            s[index] = f'${new_price:.2f}'
        return " ".join(s)
