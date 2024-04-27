class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        auto check = [&](int i, int j) -> bool {
            int a = 0;
            a += grid[i][j] == 'W';
            a += grid[i + 1][j] == 'W';
            a += grid[i][j + 1] == 'W';
            a += grid[i + 1][j + 1] == 'W';
            return a != 2;
        };
        
        return check(0, 0) || check(1, 1) || check(0, 1) || check(1, 0);
    }
};
