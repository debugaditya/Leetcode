class Solution {
public:
    bool wordPattern(string p, string str) {
        vector<string>s; string temp="";
        for(auto it:str){
            if(it==' '){
                s.push_back(temp);
                temp="";
            }
            else temp+=it;
        }
        s.push_back(temp);
        if(p.size()!=s.size()) return false;
        unordered_map<string,char>mp;
        unordered_map<char,string>mp1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]!=p[i]) return false;
            if(mp1.find(p[i])!=mp1.end()&&mp1[p[i]]!=s[i]) return false;
            mp[s[i]]=p[i];
            mp1[p[i]]=s[i];
        }
        return true;
    }
};
