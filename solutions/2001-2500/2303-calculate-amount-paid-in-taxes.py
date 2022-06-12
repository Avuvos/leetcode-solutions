class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        tax = 0
        prev_money = brackets[0][0]
        tax += min(income, prev_money) * brackets[0][1]/100
        income -= prev_money
        if income <= 0:
            return tax

        for i in range(1, len(brackets)):
            curr_money_to_pay = brackets[i][0] - prev_money
            tax += min(income, max(curr_money_to_pay, 0)) * brackets[i][1]/100
            income -= curr_money_to_pay
            if income <= 0:
                return tax
            prev_money = brackets[i][0]
        return tax
