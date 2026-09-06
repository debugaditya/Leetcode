class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<vector<int>>>>vis(m,vector<vector<vector<int>>>(n,vector<vector<int>>(k+1,vector<int>(5,INT_MAX))));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; int ans=INT_MAX;
        pq.push({grid[0][0],0,0,k,4}); vis[0][0][k][4]=grid[0][0];
        while(!pq.empty()){
            int dist=pq.top()[0],i=pq.top()[1],j=pq.top()[2],turns=pq.top()[3],prev=pq.top()[4]; pq.pop();
            if(i==m-1&&j==n-1) return dist;
            if(i>0){
                int new_turn=turns-((prev==0||prev==4)?0:1),new_prev=0;
                if(new_turn>=0&&vis[i-1][j][new_turn][new_prev]>dist+grid[i-1][j]){
                    vis[i-1][j][new_turn][new_prev]=dist+grid[i-1][j];
                    pq.push({dist+grid[i-1][j],i-1,j,new_turn,0});
                }
            } 
            if(i<m-1){
                int new_turn=turns-((prev==1||prev==4)?0:1),new_prev=1;
                if(new_turn>=0&&vis[i+1][j][new_turn][new_prev]>dist+grid[i+1][j]){
                    vis[i+1][j][new_turn][new_prev]=dist+grid[i+1][j];
                    pq.push({dist+grid[i+1][j],i+1,j,new_turn,1});
                }
            } 
            if(j>0){
                int new_turn=turns-((prev==2||prev==4)?0:1),new_prev=2;
                if(new_turn>=0&&vis[i][j-1][new_turn][new_prev]>dist+grid[i][j-1]){
                    vis[i][j-1][new_turn][new_prev]=dist+grid[i][j-1];
                    pq.push({dist+grid[i][j-1],i,j-1,new_turn,2});
                }
            } 
            if(j<n-1){
                int new_turn=turns-((prev==3||prev==4)?0:1),new_prev=3;
                if(new_turn>=0&&vis[i][j+1][new_turn][new_prev]>dist+grid[i][j+1]){
                    vis[i][j+1][new_turn][new_prev]=dist+grid[i][j+1];
                    pq.push({dist+grid[i][j+1],i,j+1,new_turn,3});
                }
            } 
        }
        return ans==INT_MAX?-1:ans;
    }
};
