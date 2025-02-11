class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp=s.substr(0,part.size());
        for(int i=0;i<=s.size()-part.size();i++){
            if(s.size()<part.size()||temp.size()<part.size()) break;
            if(temp==part){
                s.erase(i,part.size());
                i=0;
                temp=s.substr(i,part.size());
                i--;
            }
            else{
                temp.erase(temp.begin());
                if(i+part.size()<s.size()) temp.push_back(s[i+part.size()]);
            }
        }
        return s;
    }
};
