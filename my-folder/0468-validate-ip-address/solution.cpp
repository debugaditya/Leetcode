class Solution {
public:
    string validIPAddress(string queryIP) {
        bool d1=true,d2=true; string s=""; int cnt1=0,cnt2=0;
        for(auto it:queryIP){
            if(isalpha(it)){
                d1=false;
                if(tolower(it)>'f') d2=false;
                s+=it;
            }
            else if(it=='.'){
                if(s.size()==0||s.size()>3) d1=false;
                if(d1&&((s[0]=='0'&&s.size()>1)||stoi(s)>255||stoi(s)<0)) d1=false; s=""; cnt1++;
                d2=false; if(cnt1>3) d1=false;
            }
            else if(it==':'){
                if(d2&&(s.size()>4||s.size()<1)) d2=false; s=""; cnt2++;
                d1=false; if(cnt2>7) d2=false;
            }
            else s+=it;
            if(!d1&&!d2) return "Neither";
        }
        if(s.size()==0) return "Neither";
        if(s.size()>3) d1=false;
        if(d1&&((s[0]=='0'&&s.size()>1)||stoi(s)>255||stoi(s)<0)) d1=false; 
        if(d2&&(s.size()>4||s.size()<1)) d2=false;
        if(d1&&cnt1==3) return "IPv4";
        if(d2&&cnt2==7) return "IPv6";
        return "Neither";
    }
};
