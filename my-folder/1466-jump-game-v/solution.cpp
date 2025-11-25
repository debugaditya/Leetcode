class Solution {
public:
    vector<int>dp;
    int dfs(int i,int &d,vector<int>&arr){
        if(dp[i]!=-1) return dp[i]; int ans=0;
        for (int j=i-1;j>=max(0,i-d)&&arr[j]<arr[i]; j--) ans=max(ans,dfs(j,d,arr));
        for (int j=i+1;j<=min((int)arr.size()-1,i+d)&&arr[j]<arr[i];j++) ans=max(ans,dfs(j,d,arr));
        return dp[i]=1+ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        dp.resize(arr.size(),-1); int ans=0;
        for(int i=0;i<arr.size();i++) ans=max(ans,dfs(i,d,arr));
        return ans;
    }
};
