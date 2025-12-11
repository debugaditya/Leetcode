class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a=big; b=medium; c=small;
    }
    
    bool addCar(int d) {
        if(d==1) {a--; return a>=0;}
        if(d==2) {b--; return b>=0;}
        c--; return c>=0;
    }

};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
