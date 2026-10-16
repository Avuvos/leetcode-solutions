class BusBooking {
public:
    int total_time, min_time;
    vector<array<int, 4>> cost;

    BusBooking(int n) {
        total_time = 0;
        min_time = 0;
        cost = vector<array<int, 4>>(n, {0, 0, 0, 0});
    }
    
    void toggle(string seat) {
        int p = (seat[0] - 'A');
        int row = stoi(seat.substr(1)) - 1;
        if (cost[row][p] != 0) {
            min_time--;
            total_time -= cost[row][p];
            cost[row][p] = 0;
            return;
        }
        cost[row][p] = 1;
        if ((p == 0 && cost[row][1] != 0) || (p == 3 && cost[row][2] != 0)) {
            cost[row][p] += 2;
        }
        min_time++;
        total_time += cost[row][p];
    }
    
    int getTotalTime() {
        return total_time;
    }
    
    int getMinTime() {
        return min_time;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
