class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0, used = 0;
        while (mainTank > 0) {
            ans += 10;
            mainTank--;
            used++;
            if (used == 5 && additionalTank > 0) {
                mainTank++;
                additionalTank--;
                used = 0;
            }
        }
        return ans;
    }
};
