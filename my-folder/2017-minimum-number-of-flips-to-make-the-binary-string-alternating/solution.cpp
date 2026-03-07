class Solution {
public:
    int minFlips(string s) {
        string t=s+s; int cnt=0,mini=s.size()+1;
        for(int i=0;i<t.size();i++){
            if(i%2+'0'==t[i]) cnt++;
            if(i>=s.size()) if((i-s.size())%2+'0'==t[i-s.size()]) cnt--;
            if(i>=s.size()-1) mini=min({mini,cnt,(int)s.size()-cnt});
        }
        return mini;
    }
};
