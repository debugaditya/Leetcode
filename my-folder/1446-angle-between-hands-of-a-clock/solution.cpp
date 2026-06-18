class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(abs(6*minutes-1.0*((1.0*minutes/60)*30+1.0*30*(hour%12))),360-abs(6*minutes-1.0*((1.0*minutes/60)*30+1.0*30*(hour%12))));
    }
};
