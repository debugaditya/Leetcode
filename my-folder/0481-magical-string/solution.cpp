class Solution {
public:
    int magicalString(int n) {
        int cnt=1; string s="122"; int z=2;
        while(z<n){
            if(s[z]=='1') cnt++;
            char c=(3-(s.back()-'0'))+'0';
            if(s[z]=='1') s+=c;
            else{s+=c; s+=c;}
            z++;
        } 
        return cnt;
    }
};
