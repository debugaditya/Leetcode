class Solution {
public:
    bool canConstruct(string r, string m) {
        int cnt=0; vector<int>mp(26,0);
        for(auto it:r) {mp[it-'a']++; if(mp[it-'a']==1) cnt++;}
        for(auto it:m) {mp[it-'a']--; if(mp[it-'a']==0) cnt--; if(cnt==0) return true;}
        return false;
    }
};
