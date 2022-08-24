class Solution {
public:
    bool search(int n, long long p) {
        if (p == n) return true;
        else if (p > n) return false;
        long long current = 3 * p;
        return search(n, current);
    }
    
    bool isPowerOfThree(int n) {
        return search(n, 1);
    }
};
