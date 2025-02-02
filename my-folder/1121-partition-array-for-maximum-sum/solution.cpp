class Solution {
public:
    int f(vector<int>& arr, int k,int start,vector<int>&dp){
        if(start>=arr.size()) return 0;
        if(dp[start]!=-1) return dp[start];
        int maxi=INT_MIN;
        int maxi2=INT_MIN;
        for (int i = start; i < min((int)arr.size(), start + k); i++){
            maxi=max(maxi,arr[i]);
            maxi2=max(maxi2,(maxi*(i-start+1))+f(arr,k,i+1,dp));
        }
        return dp[start]=maxi2;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(arr,k,0,dp);
    }
};
