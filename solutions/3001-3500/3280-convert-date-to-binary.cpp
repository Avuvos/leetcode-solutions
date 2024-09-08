class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        string ans;
        
        auto conv = [&](int x) -> string {
            string res;
            while (x > 0) {
                if (x & 1) {
                    res += '1';
                } else {
                    res += '0';
                }
                x /= 2;
            }
            reverse(res.begin(), res.end());
            return res;
        };
        
        ans += conv(year);
        ans += '-';
        ans += conv(month);
        ans += '-';
        ans += conv(day);
        
        return ans;
    }
};
