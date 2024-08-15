class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (auto &c: bills) {
            if (c == 5) {
                fives++;
            } else if (c == 10) {
                if (!fives) {
                    return false;
                }
                fives--;
                tens++;
            } else if (c == 20) {
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            } else {
                assert(false);
            }
        }
        return true;
    }
};
