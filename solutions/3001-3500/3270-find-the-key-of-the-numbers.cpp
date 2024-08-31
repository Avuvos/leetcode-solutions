class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<vector<int>> dig(3);
        auto add = [&](int index, int num) -> void {
            int iter = 0;
            while (iter < 4) {
                dig[index].push_back(num % 10);
                num /= 10;
                iter++;
            }
            reverse(dig[index].begin(), dig[index].end());
        };
        add(0, num1);
        add(1, num2);
        add(2, num3);
        int key = 0;
        for (int i = 0; i < 4; i++) {
            int mn = 1e9;
            for (int j = 0; j < 3; j++) {
                mn = min(mn, dig[j][i]);
            }
            key *= 10;
            key += mn;
        }
        return key;
    }
};
