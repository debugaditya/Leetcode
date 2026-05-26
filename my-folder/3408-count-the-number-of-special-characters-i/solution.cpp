class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>mp(52,0); int cnt=0;
        for(auto &it:word){
            char c=toupper(it),d=tolower(it);
            if(c==it&&mp[d-'a']>0&&mp[it-'A'+26]==0) cnt++;
            if(d==it&&mp[c-'A'+26]>0&&mp[it-'a']==0) cnt++;
            mp[it-(c==it?'A':'a')+(c==it?26:0)]++;
        }
        return cnt;
    }
};
