class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, t = 0, f = 0, maxFreq = 0;
        for (int right = 0, left = 0; right < answerKey.size(); right++) {
            t += answerKey[right] == 'T';
            f += answerKey[right] == 'F';
            maxFreq = max(t, f);
            while (right - left + 1 - maxFreq > k) {
                t -= answerKey[left] == 'T';
                f -= answerKey[left] == 'F';
                left++;
                maxFreq = max(t, f);
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
