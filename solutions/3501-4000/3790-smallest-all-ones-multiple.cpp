class Solution {
public:
    int minAllOneMultiple(int k) {
        vector<bool> seen(k, false);
        seen[1] = true;
        int n = 1, ans = 1;
        while (n % k != 0) {
            ans++;
            n = (n * 10 + 1) % k;
            if (seen[n]) {    
                ans = -1;
                break;
            }
            seen[n] = true;
        }
        return ans;
    }
};
