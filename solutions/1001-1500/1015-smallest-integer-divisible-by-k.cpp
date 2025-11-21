class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        int s = 1;
        int r = k % 10;
        int prev = 1;
        set<int> seen;
        int n = 2;
        while (true) {
            int md = (prev * 10) % k;
            prev = md;
            s = (s + md) % k;
            if (s == 0) return n;
            if (seen.contains(s)) {
                return -1;
            }
            seen.insert(s);
            n++;
        }
        return -1;
    }
};

// 1 = 1
// 11 = 1 + 10
// 111 = 1 + 10 + 100
// 1111 = 1 + 10 + 100 + 1000
// if y % k = z (where y = 1000..)
//then (y * 10) % k = y % k * 10 % k % k = z * 10 % k 
