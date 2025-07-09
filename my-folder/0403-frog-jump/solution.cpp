class Solution {
public:
    bool f(vector<int>& stones,unordered_map<int,int>&mp,int index,int last,vector<vector<int>>&dp){
        if(index==stones.size()-1) return true;
        if(dp[index][last]!=-1) return dp[index][last];
        bool ans=false;
        if(mp.count(stones[index]+last-1)&&last>0) ans|=f(stones,mp,mp[stones[index]+last-1],last-1,dp);
        if(mp.count(stones[index]+last)&&last>0) ans|=f(stones,mp,mp[stones[index]+last],last,dp);
        if(mp.count(stones[index]+last+1)) ans|=f(stones,mp,mp[stones[index]+last+1],last+1,dp);
        return dp[index][last]=ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp; vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        for(int i=0;i<stones.size();i++) mp[stones[i]]=i; 
        return f(stones,mp,0,0,dp);
    }
};
