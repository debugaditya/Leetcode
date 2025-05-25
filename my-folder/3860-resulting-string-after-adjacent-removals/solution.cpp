class Solution {
public:
    string resultingString(string s) {
        int l=0,r=1;
        while(r<s.size()){
            if(abs(s[r]-'0'-(s[l]-'0'))%26==1||abs(s[r]-'0'-(s[l]-'0'))%26==25){
                s.erase(s.begin()+r);
                s.erase(s.begin()+l);
                l=max(0,l-1); r=max(r-1,1);
            }
            else{l++; r++;}
        }
        return s;
    }
};
