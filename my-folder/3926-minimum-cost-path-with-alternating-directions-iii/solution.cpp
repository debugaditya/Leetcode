class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& p) {
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(2,LLONG_MAX)));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq; dp[0][0][1]=1;
        pq.push({1,0,0,1});
        while(!pq.empty()){
            long long cost=pq.top()[0],i=pq.top()[1],j=pq.top()[2],parity=pq.top()[3];
            pq.pop();
            if (cost != dp[i][j][parity]) continue;
            if(dp[i][j][1-parity]>1ll*cost+p[i][j]) {pq.push({1ll*cost+p[i][j],i,j,1-parity}); dp[i][j][1-parity]=1ll*cost+p[i][j];}
            if(parity==1){
                if(i+1<m&&dp[i+1][j][1-parity]>1ll*cost+(i+2)*(j+1)) {pq.push({1ll*cost+(i+2)*(j+1),i+1,j,1-parity}); dp[i+1][j][1-parity]=1ll*cost+1ll*(i+2)*(j+1);}
                if(j+1<n&&dp[i][j+1][1-parity]>1ll*cost+(i+1)*(j+2)) {pq.push({1ll*cost+(i+1)*(j+2),i,j+1,1-parity}); dp[i][j+1][1-parity]=1ll*cost+1ll*(i+1)*(j+2);}
                if(i-1>=0&&dp[i-1][j][1-parity]>1ll*cost+(i)*(j+1)+p[i][j]) {pq.push({1ll*cost+(i)*(j+1)+p[i][j],i-1,j,1-parity}); dp[i-1][j][1-parity]=1ll*cost+1ll*(i)*(j+1)+p[i][j];}
                if(j-1>=0&&dp[i][j-1][1-parity]>1ll*cost+(i+1)*(j)+p[i][j]) {pq.push({1ll*cost+(i+1)*(j)+p[i][j],i,j-1,1-parity}); dp[i][j-1][1-parity]=1ll*cost+1ll*(i+1)*(j)+p[i][j];}
            }
            else{
                if(i+1<m&&dp[i+1][j][1-parity]>1ll*cost+(i+2)*(j+1)+p[i][j]) {pq.push({1ll*cost+(i+2)*(j+1)+p[i][j],i+1,j,1-parity}); dp[i+1][j][1-parity]=1ll*cost+1ll*(i+2)*(j+1)+p[i][j];}
                if(j+1<n&&dp[i][j+1][1-parity]>1ll*cost+(i+1)*(j+2)+p[i][j]) {pq.push({1ll*cost+(i+1)*(j+2)+p[i][j],i,j+1,1-parity}); dp[i][j+1][1-parity]=1ll*cost+1ll*(i+1)*(j+2)+p[i][j];}
                if(i-1>=0&&dp[i-1][j][1-parity]>1ll*cost+(i)*(j+1)) {pq.push({1ll*cost+(i)*(j+1),i-1,j,1-parity}); dp[i-1][j][1-parity]=1ll*cost+1ll*(i)*(j+1);}
                if(j-1>=0&&dp[i][j-1][1-parity]>1ll*cost+(i+1)*(j)) {pq.push({1ll*cost+(i+1)*(j),i,j-1,1-parity}); dp[i][j-1][1-parity]=1ll*cost+1ll*(i+1)*(j);}
            }
        }
        return min(dp[m-1][n-1][0], dp[m-1][n-1][1]);
    }
};
