class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int en = initialEnergy;
        int ex = initialExperience;
        int train = 0;
        int trainEx = 0;
        
        int sumEn = 0;
        for (int i = 0; i < energy.size(); i++) {
            
            sumEn += energy[i];
        }
        train = sumEn + 1;
        
        for (int i = 0; i < energy.size(); i++) {
            if (ex > experience[i]) {
                ex += experience[i];
            }
            else  {
                trainEx += (experience[i] - ex + 1);
                ex = experience[i] + 1;
                ex += experience[i];
            }
        }
        
        return trainEx + max(0, train - en);
    }
};
