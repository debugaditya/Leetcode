class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        int m=water.size();
        int n=water[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> ans(m,vector<int>(n,10000000));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(water[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if(i-1>=0 &&  ans[i-1][j]>ans[i][j]+1){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
            if(i+1<m && ans[i+1][j]>ans[i][j]+1){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
            if(j-1>=0 && ans[i][j-1]>ans[i][j]+1){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
            if(j+1<n && ans[i][j+1]>ans[i][j]+1){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            q.pop();
        }
        return ans;
    }
};
