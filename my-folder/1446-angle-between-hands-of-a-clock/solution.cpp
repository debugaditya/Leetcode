class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=0;
        ans+=6*minutes;
        ans-=1.0*((1.0*minutes/60)*30+1.0*30*(hour%12));
        ans=abs(ans);
        return min(ans,(double) 360-ans);
    }
};
