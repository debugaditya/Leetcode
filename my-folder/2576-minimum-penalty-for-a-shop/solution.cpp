class Solution {
public:
    int bestClosingTime(string c) {
        vector<int>mp(c.size(),0); int cnt=c[0]=='N'?1:0;
        for(int i=1;i<c.size();i++){
            mp[i]+=cnt;
            if(c[i]=='N') cnt++;
        }
        int mini=cnt,ans=c.size(); cnt=0;
        for(int i=c.size()-1;i>=0;i--){
            if(c[i]=='Y') cnt++;
            mp[i]+=cnt;
            if(mini>=mp[i]) ans=i;
            mini=min(mini,mp[i]);
        }
        return ans;
    }
};
