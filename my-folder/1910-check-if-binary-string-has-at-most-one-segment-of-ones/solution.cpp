class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'&&s[i-1]=='1') cnt++;
            if(cnt==2) return false; 
        }
        if(s.back()=='1') cnt++;
        return cnt<=1;
    }
};
