class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int s=0,e=c.size()-1,ans=0;
        unordered_map<int,int>mp(c.size()); 
        for(int i=0;i<c.size();i++) mp[i]=mp[i-1]+c[i];
        for(int i=0;i<=k;i++){
            int pre=mp[i-1];
            int suff=mp[c.size()-1]-mp[c.size()-k+i-1];
            ans=max(ans,suff+pre);
        }
        return ans;
    }
};
