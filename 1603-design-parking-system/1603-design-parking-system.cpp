class ParkingSystem {
public:
    vector<int> p;
    ParkingSystem(int big, int medium, int small) {
        p.resize(4, 0);
        p[1] = big;
        p[2] = medium;
        p[3] = small;
    }
    
    bool addCar(int carType) {
        if (p[carType] > 0) {
            p[carType]--;
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