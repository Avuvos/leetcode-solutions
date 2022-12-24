class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        //if gcd is 1, we want b st (b - b/lcm(d1, d2)) = u1 + u2
       long long d = gcd(d1, d2);
       long long l = lcm((long long)d1, (long long)d2);
       long long left = 1, right = 1e10;
       long long ans = 1e10;
       while (left <= right) {
           long long b = left + (right - left)/2;
           bool cond1 = b - (b / l) >= u1 + u2;
           bool cond2 = b - (b / d1) >= u1;
           bool cond3 = b - (b / d2) >= u2;
           if (cond1 && cond2 && cond3) {
               ans = b;
               right = b - 1;
           } else {
               left = b + 1;
           }
       }
       return ans;
    }
};
