class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (auto word: words) {
            string transform = "";
            for (int i = 0; i < word.size(); i++) {
                transform += morse[word[i] - 'a'];
            }
            s.insert(transform);
        }
        return s.size();
    }
};
