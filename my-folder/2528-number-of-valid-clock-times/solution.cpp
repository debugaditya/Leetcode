class Solution {
public:
    int countTime(string time) {
        int min=1,hour=1;
        if(time.back()=='?') min*=10;
        if(time[3]=='?') min*=6;
        if(time[0]!='?'&&time[1]!='?') return min;
        if(time[0]=='?'&&time[1]=='?') return 24*min;
        if(time[0]=='?'){
            if(time[1]<='3') hour*=3;
            else hour*=2;
        }
        if(time[1]=='?'){
            if(time[0]<='1') hour*=10;
            else hour*=4;
        }
        return hour*min;
    }
};
