class Solution {
public:
    string largestPalindrome(int n, int k) {
        if (k == 1 || k == 3 || k == 9) {
            return string(n, '9');
        }
        if (k == 2) {
            return n <= 2 ? string(n, '8') : "8" + string(n - 2, '9') + "8";
        }
        if (k == 4) {
            return n <= 4 ? string(n, '8') : "88" + string(n - 4, '9') + "88";
        }
        if (k == 5) {
            return n <= 2 ? string(n, '5') : "5" + string(n - 2, '9') + "5";
        }
        if (k == 6) {
            if (n <= 2) {
                return string(n, '6');
            }
            if (n == 3) {
                return "888";
            }
            if (n == 4) {
                return "8778";
            }
            if (n == 5) {
                return "89898";
            }
            if (n % 2 == 0) {
                return "8" + string((n - 4) / 2, '9') + "77" + string((n - 4) / 2 , '9') + "8";
            }
            return "8" + string((n - 3) / 2 , '9') + "8" + string((n - 3) / 2, '9') + "8";
        }
        if (k == 7) {
            if (n <= 2) {
                return string(n, '7');
            }
            map<int, string> mp = {{0, ""}, {1, "7"}, {2, "77"}, {3, "959"}, {4, "9779"},
                                   {5, "99799"}, {6, "999999"}, {7, "9994999"}, {8, "99944999"},
                                   {9, "999969999"}, {10, "9999449999"}, {11, "99999499999"}};
            int q = n / 12;
            int r = n % 12;
            return string(6 * q, '9') + mp[r] + string(6 * q, '9');
        }
        if (k == 8) {
            return n <= 6 ? string(n, '8') : "888" + string(n - 6, '9') + "888";
        }
        return "";
    }
};
