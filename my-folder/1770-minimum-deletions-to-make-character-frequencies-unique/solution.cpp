class Solution {
public:
    int minDeletions(string s) {
        int ans=0; vector<int>mp(26,0);
        for(auto it:s) mp[it-'a']++;
        sort(mp.begin(),mp.end());
        for(int i=25;i>=1;i--){
            if(mp[i-1]==0) break;
            if(mp[i-1]>=mp[i]){
                ans+=abs(mp[i]-mp[i-1])+1;
                mp[i-1]-=abs(mp[i]-mp[i-1])+1;
                if(mp[i]==0) {ans--; mp[i-1]=0;}
            }
        }
        return ans;
    }
};
