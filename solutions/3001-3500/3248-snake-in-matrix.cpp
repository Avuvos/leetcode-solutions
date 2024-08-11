class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = count(commands.begin(), commands.end(), "DOWN") - 
                count(commands.begin(), commands.end(), "UP");
        
        int j = count(commands.begin(), commands.end(), "RIGHT") -
                count(commands.begin(), commands.end(), "LEFT");
        
        return i * n + j;
    }
};
