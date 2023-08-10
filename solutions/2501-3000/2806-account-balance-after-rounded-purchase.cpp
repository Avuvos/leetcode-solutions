class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int pay, r = purchaseAmount % 10;
        if (r == 0) {
            pay = purchaseAmount;
        } else if (r >= 5) {
            pay = purchaseAmount + 10 - r;
        } else {
            pay = purchaseAmount - r;
        }
        return 100 - pay;
    }
};
