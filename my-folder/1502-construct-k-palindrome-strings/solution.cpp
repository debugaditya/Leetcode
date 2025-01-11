class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()) return false;
        map<char,int>mp;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2!=0) cnt++;
        }
        if(cnt>k) return false;
        return true;
    }
};
