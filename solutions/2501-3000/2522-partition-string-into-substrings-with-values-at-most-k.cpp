class Solution {
public:
    int minimumPartition(string s, int k) {
        if (s.size() == 1) return ((s[0] - '0') <= k ? 1 : -1);
        
        long long curr = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            curr *= 10;
            curr += (s[i] - '0');
            //cout << "curr = " << curr << endl;
            if (curr > k) {
                ans++;
                curr = (s[i] - '0');
            }
            if (curr > k && curr < 10) return -1;
        }
        return ans + 1;
        
        
    }
};
