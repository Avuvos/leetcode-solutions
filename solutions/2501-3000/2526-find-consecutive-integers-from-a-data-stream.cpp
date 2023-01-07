class DataStream {
public:
    int kk;
    int val;
    int streak;
    DataStream(int value, int k) {
        kk = k;
        val = value;
        streak = 0;
    }
    
    bool consec(int num) {
        if (num == val) {
            streak++;
        } else {
            streak = 0;
        }
        return streak >= kk;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
