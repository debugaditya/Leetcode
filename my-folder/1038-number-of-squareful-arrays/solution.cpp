class Solution {
public:
    bool check(int n){
        int l=0,r=100001;
        while(l<=r){
            int mid=(l+r)/2;
            if(1LL*mid*mid==n) return true;
            if(1LL*mid*mid<n) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
    int f(vector<vector<int>>&adj,int i,int mask,vector<int>&pw,vector<vector<int>>&dp){
        if (((1 << i) & mask) != 0) return 0;
        mask+=pw[i]; if(mask==2*pw.back()-1) return 1;
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans=0;
        for(auto it:adj[i]) ans+=f(adj,it,mask,pw,dp);
        return dp[i][mask]=ans;
    }
    int fact(int n){
        int prod=1;
        while(n>0) {prod*=n; n--;}
        return prod;
    }
    void powers(vector<int>&pw){
        int j=1;
        for(int i=0;i<pw.size();i++){pw[i]=j; j*=2;}
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>adj(nums.size()),dp(nums.size(),vector<int>(pow(2,n),-1)); vector<int>pw(nums.size()); int ans=0;
        unordered_map<int,int>mp; powers(pw);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(check(nums[i]+nums[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<nums.size();i++) {ans+=f(adj,i,0,pw,dp); mp[nums[i]]++;}
        for(auto it:mp) ans/=fact(it.second);
        return ans;
    }
};
