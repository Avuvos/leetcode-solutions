class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children;
        int ans = 0;
        int left = -1;
        for (int i = 0; i < children - 1; i++) {
            if (money >= 7) {
                ans++;
                money -= 7;
            } else {
                break;
            }
            left = i;
        }
        if (money == 3 && left == children - 2) ans--;
        if (money == 7) ans++;
        return max(0, ans);
    }
};
