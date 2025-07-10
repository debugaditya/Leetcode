class Solution {
public:
    string findValidPair(string s) {
        vector<int>mp(10,0);
        for(auto it:s) mp[it-'0']++;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]&&mp[s[i]-'0']==s[i]-'0'&&mp[s[i+1]-'0']==s[i+1]-'0') return string(1, s[i]) + string(1, s[i+1]);
        }
        return "";
    }
};
