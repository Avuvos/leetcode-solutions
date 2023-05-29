class ParkingSystem {
public:
    vector<int> park;
    ParkingSystem(int big, int medium, int small) {
        park.assign(4, 0);
        park[1] = big;
        park[2] = medium;
        park[3] = small;
    }
    
    bool addCar(int carType) {
        if (park[carType] > 0) {
            park[carType]--;
            return true;
        }
        return false;
    }
};
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
