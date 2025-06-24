class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>v1; unordered_map<char,int>v2;
        for(int i=0;i<s.size();i++){
            if(!v1.count(s[i])&&!v2.count(t[i])){
                v1[s[i]]=i;
                v2[t[i]]=i;
            }
            else if(!v1.count(s[i])||!v2.count(t[i])) return false;
            else{
                if(v1[s[i]]!=v2[t[i]]) return false;
                v1[s[i]]=i;
                v2[t[i]]=i;
            }
        }
        return true;
    }
};
