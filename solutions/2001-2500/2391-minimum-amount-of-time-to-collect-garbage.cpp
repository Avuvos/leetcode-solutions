class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<long long> prefix(n + 1, 0); //prefix[i] time to travel to ith house
        for (int i = 0; i < n - 1; ++i) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1] += travel[i];
        }

        int maxG = 0, maxM = 0, maxP = 0;
        int collecting_time = 0;
        for (int index = 0; index < n; ++index) {
            string current = garbage[index];
            collecting_time += current.size();
            for (int j = 0; j < current.size(); j++) {
                if (current[j] == 'M') {
                    maxM = index;
                }
                else if (current[j] == 'P') {
                    maxP = index;
                }
                else {
                    maxG = index;
                }
            }
        }

        collecting_time += prefix[maxM];
        collecting_time += prefix[maxG];
        collecting_time += prefix[maxP];
        return collecting_time;
    }
};
