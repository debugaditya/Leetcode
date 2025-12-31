class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int i,int j,vector<vector<int>>&vis){
        if(j==adj[0].size()||i==-1||j==-1||vis[i][j]+adj[i][j]>0) return false;
        if(i==adj.size()-1) return true; vis[i][j]=1;
        if(dfs(adj,i+1,j,vis)||dfs(adj,i-1,j,vis)||dfs(adj,i,j+1,vis)||dfs(adj,i,j-1,vis)) return true;
        return false;
    }
    bool f(int row, int col, int mid, vector<vector<int>>& cells){
        vector<vector<int>>adj(row,vector<int>(col,0)),vis(row,vector<int>(col,0));
        for(int i=0;i<=mid;i++) adj[cells[i][0]-1][cells[i][1]-1]=1;
        for(int i=0;i<col;i++) if(vis[0][i]==0) if(dfs(adj,0,i,vis)) return true;
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,r=cells.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(row,col,mid,cells)) l=mid+1;
            else r=mid-1;
        }
        return r+1;
    }
};
