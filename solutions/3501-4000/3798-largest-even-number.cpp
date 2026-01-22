class Solution {
public:
    string largestEven(string s) {
        while (!s.empty() && int(s.back()) % 2 == 1) {
            s.pop_back();
        }
        return s;
    }
};
