class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long v2 = ((long long)length)*((long long)width);
        long long v = v2* (long long)height;
        bool bulk = v >= 1e9 || length >= 1e4 || width >= 1e4 || height >= 1e4;
        bool heavy = mass >= 100;
        if (bulk && heavy) return "Both";
        if (!bulk && !heavy) return "Neither";
        if (bulk && !heavy) return "Bulky";
        return "Heavy";
    }
};
