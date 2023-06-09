class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (letters[mid] > target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans == -1 ? letters[0] : letters[ans]; 
    }
};
