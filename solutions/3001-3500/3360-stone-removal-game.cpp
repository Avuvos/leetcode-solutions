class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        int aliceTurn = 1;
        while (n > 0) {
            if (n < x) break;
            n -= x;
            x -= 1;
            aliceTurn ^= 1;
        }
        return !aliceTurn;
    }
};
