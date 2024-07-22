class Solution {
public:
    string losingPlayer(int x, int y) {
        int alice_turn = 1;
        while (true) {
            if (x < 1 || y < 4) {
                break;
            }
            x -= 1;
            y -= 4;
            alice_turn ^= 1;
        }
        return alice_turn ? "Bob" : "Alice";
    }
};
