class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int R_index = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == '.') continue;
            else if (dominoes[i] == 'L') {
                if (R_index == -1) {
                    for (int j = i - 1; j >= 0 && dominoes[j] == '.'; j--) {
                        dominoes[j] = 'L';
                    }
                }
                else {
                    int k = i - 1;
                    for (int j = R_index + 1; j < k; j++) {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                        k--;
                    }
                    R_index = -1;
                }
            }
            else { // 'R'
                if (R_index != -1) {
                    for (int j = R_index + 1; j < i; j++) {
                        dominoes[j] = 'R';
                    }
                }
                R_index = i;
            }
        }
        if (R_index != -1) {
            for (int j = R_index + 1; j < n; j++) {
                dominoes[j] = 'R';
            }
        }
        return dominoes;
    }
};
