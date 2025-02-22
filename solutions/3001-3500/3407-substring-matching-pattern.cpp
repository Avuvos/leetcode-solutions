class Solution {
public:
    bool hasMatch(string s, string p) {
        int pos = p.find("*");
        string pref = p.substr(0, pos);
        string suf = p.substr(pos + 1);
        bool found_pref = pref.size() == 0, found_suf = suf.size() == 0;
        int i = 0;
        while (i < s.size() - pref.size() + 1 && !found_pref) {
            if (s.substr(i, pref.size()) == pref) {
                found_pref = true;
                i += pref.size();
                break;
            }
            i += 1;
        }
        if (!found_pref) return false;
        while (i < s.size() - suf.size() + 1 && !found_suf) {
            if (s.substr(i, suf.size()) == suf) {
                found_suf = true;
            }
            i += 1;
        }
        if (!found_suf) return false;
        
        return true;
    }
};
