class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        long long res = 0;
        int prev_index = 0;
        for (int index = 1; index < colors.size(); index++) {
            if (colors[index] == colors[prev_index]) {
                if (neededTime[prev_index] <= neededTime[index]) {
                    res += neededTime[prev_index];
                    prev_index = index;
                } 
                else {
                    res += neededTime[index];
                }
            } 
            else {
                prev_index = index;
            }
        }
        return res;
    }
};
