class Solution {
public:
    int f(int l,int r,vector<int>& s,vector<int>&sum,vector<vector<int>>&dp){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MIN;
        for(int i=l;i<r;i++){
            int sum1=sum[i+1]-sum[l];
            int sum2=sum[r+1]-sum[i+1];
            if(sum1==sum2) ans=max(ans,sum1+max(f(l,i,s,sum,dp),f(i+1,r,s,sum,dp)));
            else if(sum1>sum2) ans=max(ans,sum2+f(i+1,r,s,sum,dp));
            else ans=max(ans,sum1+f(l,i,s,sum,dp));
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& s) {
        vector<int>sum(s.size()+1); sum[0]=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        for(int i=1;i<sum.size();i++) sum[i]=sum[i-1]+s[i-1];
        return f(0,s.size()-1,s,sum,dp);
    }
};
