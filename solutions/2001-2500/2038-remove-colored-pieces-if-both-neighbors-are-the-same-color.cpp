class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for (int i = 0; i + 2 < colors.size(); i++) {
            string cur = colors.substr(i, 3);
            if (cur == "AAA") {
                a++;
            }
            if (cur == "BBB") {
                b++;
            }
        }
        return a > b;
    }
};
