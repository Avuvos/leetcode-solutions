class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        auto check = [&](int s) {
            int start = s;
            int p = s, m = derived.size();
            for (int i = 0; i < m - 1; i++) {
                if (derived[i] == 1) {
                    if (p == 0) s = 1;
                    else s = 0;
                } else {
                    if (p == 0) s = 0;
                    else s = 1;
                }
                p = s;
            }
            return (derived[m - 1] == p ^ start);
        };
        return check(0) || check(1);
    }
};
