class Solution {
public:
    string reverseVowels(string s) {
        vector<int> ind;
        string vowels = "aeiouAEIOU";
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                ind.push_back(i);
            }
        }
        int left = 0, right = ind.size() - 1;
        while (left <= right) {
            swap(s[ind[left]], s[ind[right]]);
            left++;
            right--;
        }
        return s;
    }
};
