class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0"; bool d=false;
        string s=""; if(num<0) {num=abs(num); d=true;}
        while(num>0){
            s+=num%7+'0';
            num/=7;
        }
        if(d) s+='-';
        reverse(s.begin(),s.end());
        return s;
    }
};
