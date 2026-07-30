class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>ans(n,0); int mini=min(x-1,y-1),maxi=max(x-1,y-1); vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j]=min(j-i,abs(mini-i)+abs(maxi-j)+1);
                dp[j][i]=dp[i][j];
            }
        }
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans[dp[i][j]-1]+=2;
        return ans;
    }
};
