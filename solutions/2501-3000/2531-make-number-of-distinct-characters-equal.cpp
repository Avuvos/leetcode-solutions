class Solution {
public:
    string ab = "abcdefghijklmnopqrstuvwxyz";
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        for (auto c: word1) mp1[c]++;
        for (auto c: word2) mp2[c]++;
        
        int uniq1 = mp1.size();
        int uniq2 = mp2.size();
                
        for (auto c: ab) {
            for (auto d: ab) {
                int u1 = uniq1, u2 = uniq2;
                if (mp1[c] > 0 && mp2[d] > 0) {
                    //cout << c << " " << d << endl;
                    //cout << mp1[c] << " " << mp2[d] << endl;
                    if (d != c) {
                        if (mp1[c] - 1 == 0) u1--;
                        if (mp2[d] - 1 == 0) u2--;

                        if (mp1[d] == 0) u1++;
                        if (mp2[c] == 0) u2++;   
                    }
                    
                    if (u1 == u2) return true;
                }
            }
        }
        return false;
        
        
    }
};
