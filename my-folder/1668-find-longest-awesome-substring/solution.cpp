class Solution {
public:
    int longestAwesome(string s) {
        vector<int>mp(1025,-2); int mask=0,ans=1; mp[0]=-1;
        for(int i=0;i<s.size();i++){
            mask^=(1<<(s[i]-'0'));
            if(mp[mask]!=-2) ans=max(ans,i-mp[mask]);
            else mp[mask]=i;
            for(int j=0;j<10;j++) if(mp[mask^(1<<j)]!=-2) ans=max(ans,i-mp[mask^(1<<j)]);
        }
        return ans;
    }
};
