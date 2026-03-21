class RideSharingSystem {
public:
    int driver_ts, rider_ts;
    map<int, int> drivers;
    map<int, int> riders;
    unordered_map<int, int> id_to_ts;
    RideSharingSystem() {
        driver_ts = 0;
        rider_ts = 0;
        drivers.clear();
        riders.clear();
        id_to_ts.clear();
    }
    
    void addRider(int riderId) {
        riders[rider_ts] = riderId;
        id_to_ts[riderId] = rider_ts;
        rider_ts++;
    }
    
    void addDriver(int driverId) {
        drivers[driver_ts] = driverId;
        driver_ts++;
    }
    
    vector<int> matchDriverWithRider() {
        if (drivers.empty() || riders.empty()) {
            return {-1, -1};
        }
        auto driver = drivers.begin();
        auto rider = riders.begin();
        vector<int> res = {driver -> second, rider -> second};
        id_to_ts.erase(rider -> second);
        riders.erase(rider);
        drivers.erase(driver);
        return res;
    }
    
    void cancelRider(int riderId) {
        auto it = id_to_ts.find(riderId);
        if (it == id_to_ts.end()) return;
        riders.erase(it -> second);
        id_to_ts.erase(it);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
