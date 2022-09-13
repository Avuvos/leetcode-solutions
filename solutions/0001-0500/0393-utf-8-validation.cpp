class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(), index = 0;
        while (index < n) {
           if ( (data[index] & (1 << 7)) == 0) {
               index++;
               continue;
            }
            int b = 0;
            while ((data[index] & (1 << (7 - b))) > 0 && b <= 5) {
                b++;
            }
            
            if (b == 1 || b > 4) return false;
            
            for (int j = 1; j < b; j++) {
                if (j + index >= n)
                    return false;
                
                if ((data[j + index] & ((1 << 7) | (1 << 6))) != (1 << 7))
                    return false;
                
            }
            index += b;
        }
        return true;
    }
};
