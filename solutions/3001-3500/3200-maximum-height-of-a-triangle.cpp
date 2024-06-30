class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto get = [&](int x, int y) -> int {
            int current = 1;
            while (true) {
                if (x < current) break;
                x -= current;
                current += 1;
                if (y < current) break;
                y -= current;
                current += 1;
            }
            return current - 1;
        };
        return max(get(red, blue), get(blue, red));
    }
};
