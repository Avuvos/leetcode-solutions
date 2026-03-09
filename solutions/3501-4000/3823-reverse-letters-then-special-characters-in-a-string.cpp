class Solution {
public:
    string reverseByType(string s) {
        auto rev = [&](string &st, bool low) -> string {
            int l = 0, r = st.size() - 1;
            while (l <= r) {
                if (low) {
                    if (islower(st[l]) && islower(st[r])) {
                        swap(st[l], st[r]);
                        l++;
                        r--;
                    } else if (islower(st[l])) {
                        r--;
                    } else {
                        l++;
                    }
                } else {
                    if (!islower(st[l]) && !islower(st[r])) {
                        swap(st[l], st[r]);
                        l++;
                        r--;
                    } else if (!islower(st[l])) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
            return st;
        };
        s = rev(s, 0);
        s = rev(s, 1);
        return s;
    }
};
