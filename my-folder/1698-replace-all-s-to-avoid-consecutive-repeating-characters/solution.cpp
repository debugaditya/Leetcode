class Solution {
public:
    string modifyString(string s) {
        if(s[0]=='?'){
            if(s[1]=='a') s[0]='b';
            else s[0]='a';
        } 
        if(s.back()=='?'){
            if(s[s.size()-2]=='a') s[s.size()-1]='b';
            else s[s.size()-1]='a';
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                if((s[i-1]-'a'+1)%26+'a'==s[i+1]) s[i]=(s[i+1]-'a'+1)%26+'a';
                else s[i]=(s[i-1]-'a'+1)%26+'a';
            }
        }
        return s;
    }
};
