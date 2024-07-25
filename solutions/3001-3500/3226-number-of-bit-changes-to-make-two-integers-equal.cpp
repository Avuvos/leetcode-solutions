class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) == k ? __builtin_popcount(n) - __builtin_popcount(n & k) : -1; 
    }
};
