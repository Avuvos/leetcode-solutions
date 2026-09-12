class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto get = [&](string t) -> array<int, 3> {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            int s = stoi(t.substr(6, 2));
            return {s, m, h};
        };
        array<int, 3> st = get(startTime), et = get(endTime);
        int hour_diff = et[2] - st[2];
        if (hour_diff == 0) {
            return 60 * (et[1] - st[1]) - st[0] + et[0];
        }
        return 3600 * (hour_diff - 1) + 60 * (60 - st[1] + et[1]) - st[0] + et[0];
    }
};
