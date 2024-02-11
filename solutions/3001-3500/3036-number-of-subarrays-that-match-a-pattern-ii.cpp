class Solution {
public:
    //KMP Algorithm – Linear Time Pattern Searching O(n+m)

    vector<int> computeLPS(string& pattern) {
        int m = (int) pattern.size();
        vector<int>lps = vector<int>(m);

        int len = 0;
        lps[0] = 0;
        int index = 1;
        while (index < m) {
            if (pattern[index] == pattern[len]) {
                len++;
                lps[index] = len;
                index++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[index] = 0;
                    index++;
                }
            }
        }
        return lps;
    }

    vector<int> searchPattern(string& txt, string& pattern, vector<int>& lps) {
        int m = (int) pattern.size();
        int n = (int) txt.size();
        vector<int> res;

        int i = 0; // index for txt
        int j = 0; // index for pattern
        while (i < n) {
            if (pattern[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != txt[i]) {
                if (j != 0) j = lps[j - 1];
                else i = i + 1;
            }
        }
        return res;
    }

    int countMatchingSubarrays(vector<int>& a, vector<int>& pattern) {
        int n = a.size(), m = pattern.size();
        string text, pat;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] < a[i + 1]) text += "1";
            else if (a[i] > a[i + 1]) text += "2";
            else text += "0";
        }
        for (auto &x: pattern) pat += to_string((x == -1 ? 2 : x));
        vector<int> lps = computeLPS(pat);
        return searchPattern(text, pat, lps).size();
    }
};
