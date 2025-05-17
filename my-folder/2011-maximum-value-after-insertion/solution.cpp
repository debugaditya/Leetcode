class Solution {
public:
    string maxValue(string s, int x) {
        if(s[0]!='-') for(int i=0;i<s.size();i++) {if(s[i]-'0'<x) {s.insert(s.begin()+i,x+'0'); return s;}}
        else for(int i=1;i<s.size();i++) {if(s[i]-'0'>x) {s.insert(s.begin()+i,x+'0'); return s;}}
        s.push_back(x+'0');
        return s;
    }
};
