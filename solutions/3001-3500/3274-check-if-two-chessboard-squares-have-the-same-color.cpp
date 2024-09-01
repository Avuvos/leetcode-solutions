class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        
        //return 0 for white, 1 for black
        auto get_color = [&](string &s) -> int {
            int r = s[1] - '0';
            if (r % 2 == 0) {
                return (s[0] - 'a') % 2 == 0;
            } else {
                return (s[0] - 'a') % 2 == 1;
            }
        };
        
        
        return get_color(coordinate1) == get_color(coordinate2);
    }
};
