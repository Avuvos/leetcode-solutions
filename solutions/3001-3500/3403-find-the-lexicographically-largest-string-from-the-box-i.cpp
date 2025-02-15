class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string ans;
        for (int i = 0; i < n; i++) {
            int best_j = -1;
            for (int j = i; j < n; j++) {
                int rem_chars = n - (j - i + 1);
                int min_req_splits = numFriends - 1;
                int min_strings_created = 1 + (i != 0) + (j != n - 1);
                if (rem_chars >= min_req_splits && min_strings_created <= numFriends) {
                    best_j = j;
                }
                if (rem_chars < min_req_splits) break;
            }
            if (best_j != -1) {
                string t = word.substr(i, best_j - i + 1);
                ans = max(ans, t);
            }
        }
        return ans;
    }
};
