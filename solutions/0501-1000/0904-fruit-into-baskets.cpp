class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = (int)fruits.size();
        int l = 0, res = 0;
        int f1 = -1, f2 = -1;
        int f1_cnt = 0, f2_cnt = 0;
        for (int r = 0; r < n; r++) {
            if (f1 == -1 || f1 == fruits[r]) {
                f1 = fruits[r];
                f1_cnt++;
            } else if (f2 == -1 || f2 == fruits[r]) {
                f2 = fruits[r];
                f2_cnt++;
            } else {
                while (f2_cnt > 0 && f1_cnt > 0 && l < r) {
                    if (fruits[l] == f1) f1_cnt--;
                    else if (fruits[l] == f2) f2_cnt--;
                    else assert(false);
                    l++;
                }
                if (f1_cnt == 0) {
                    f1 = fruits[r];
                    f1_cnt++;
                }
                else {
                    f2 = fruits[r];
                    f2_cnt++;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
