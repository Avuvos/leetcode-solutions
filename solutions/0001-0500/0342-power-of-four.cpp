class Solution {
public:
    
    bool search(int n, int exp) {
        long long curr = (long long) pow(4, exp);
        if (curr == n) return true;
        else if (curr > n) return false;
        else return search(n, exp + 1);
    }
    
    bool isPowerOfFour(int n) {
        return search(n, 0);
    }
};
