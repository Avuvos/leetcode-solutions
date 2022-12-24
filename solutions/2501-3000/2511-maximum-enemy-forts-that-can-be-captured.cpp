class Solution {
public:
    int captureForts(vector<int>& forts) {
        int one_index = -1, neg_one_index = -1;
        int zero_streak = 0;
        int res = 0;
        for (int index = 0; index < forts.size(); ++index) {
            if (forts[index] == -1 && one_index != -1) {
                res = max(res, zero_streak);
            }
            if (forts[index] == 1 && neg_one_index != -1) {
                res = max(res, zero_streak);
            }

            if (forts[index] == 1) {
                one_index = index; 
                neg_one_index = -1;
            }
            if (forts[index] == -1){
                neg_one_index = index;
                one_index = -1;
            } 

            if (forts[index] == 0) {
                zero_streak += 1;
            } else {
                zero_streak = 0;
            }
        }
        return res;
    }
};
