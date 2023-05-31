class UndergroundSystem {
public:
    map<pair<string, string>, pair<int, int>> mp;
    map<int, pair<string, int>> users;
    
    UndergroundSystem() {
        mp.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        users[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [beg, time] = users[id];
        mp[{beg, stationName}].first += (t - time);
        mp[{beg, stationName}].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [sum, cnt] = mp[{startStation, endStation}];
        return sum / (double) cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
