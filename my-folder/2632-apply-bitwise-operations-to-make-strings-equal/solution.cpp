class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int a=0,b=0,cnt1=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'&&target[i]=='1') a++;
            else if(s[i]=='1'&&target[i]=='0') b++;
            if(s[i]=='1') cnt++;
        }
        if(a==0&&b==0) return true;
        if(a>0&&b>0) return true;
        if(b==cnt&&b>0) return false;
        if(a>0&&cnt==0) return false;
        return true;
    }
};
