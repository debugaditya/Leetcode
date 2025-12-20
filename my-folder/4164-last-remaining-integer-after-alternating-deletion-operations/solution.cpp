class Solution {
public:
    long long lastInteger(long long n) {
        long long diff=2,start=1,end=n,turn=0;
        while(diff<n){
            long long t=(end-start)/diff+1;
            if(turn==0) end=start+(t-1)*diff;
            else start=end-(t-1)*diff;
            diff*=2; turn=1-turn;
        }
        if(turn==1) return end;
        return start;
    }
};
