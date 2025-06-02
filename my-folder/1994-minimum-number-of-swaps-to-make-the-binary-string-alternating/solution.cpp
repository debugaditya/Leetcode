class Solution {
public:
    int minSwaps(string s) {
        int cnt=0; int ones=count(s.begin(),s.end(),'1'); int zeroes=s.size()-ones; string alt;
        if(zeroes!=s.size()/2&&ones!=s.size()/2) return -1;
        if(zeroes>ones) alt="0";
        else alt="1";
        while(alt.size()<s.size()) alt+=1-(alt.back()-'0')+'0';
        for(int i=0;i<s.size();i++) if(s[i]!=alt[i]) cnt++;
        return s.size()%2==0?min(cnt,(int) s.size()-cnt)/2:cnt/2;
    }
};
