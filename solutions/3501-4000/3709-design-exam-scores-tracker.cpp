class ExamTracker {
public:
    map<int, pair<long long, long long>> mp; // time -> score so far
    ExamTracker() {
        mp.clear();
    }
    
    void record(int time, int score) {
        auto it = mp.rbegin();
        long long value = 0;
        if (mp.size() > 0) {
            value = it -> second.second;
        }
        mp[time] = {score, value + score};
    }
    
    long long totalScore(int startTime, int endTime) {
        auto low = mp.lower_bound(startTime);
        auto high = mp.lower_bound(endTime);

        if (high != mp.begin() && high -> first > endTime) {
            high--;
        }

        if (low != mp.begin() && low -> first > startTime) {
            low--;
        }

        auto [v_low, s_low] = low -> second;
        auto [_, s_high] = high -> second;

        long long sum_high = (high -> first <= endTime ? s_high : 0);
        long long sum_low = s_low - (low -> first >= startTime ? v_low : 0);
        
        return sum_high - sum_low;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
