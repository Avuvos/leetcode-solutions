class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256);
        for (auto& c: s) freq[c]++;
        
        sort(s.begin(), s.end(), [&](const char& c1, const char& c2) {
            return freq[c1] == freq[c2] ? c1 < c2 : freq[c1] > freq[c2];
        });
        
        return s;
    }
};
