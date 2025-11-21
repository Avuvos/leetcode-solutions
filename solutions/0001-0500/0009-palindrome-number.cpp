class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        vector<int> d;
        while (x > 0) {
            d.push_back(x % 10);
            x /= 10;
        }
        int l = 0, r = d.size() - 1;
        while (l < r) {
            if (d[l] != d[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
