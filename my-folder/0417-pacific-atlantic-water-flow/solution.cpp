class Solution {
public:
    void dfs(vector<vector<int>>& h,int i,int j,int &m,int &n,vector<vector<bool>>&vis){
        if(vis[i][j]) return;
        vis[i][j]=true;
        if(j+1<n&&h[i][j]<=h[i][j+1]) dfs(h,i,j+1,m,n,vis);
        if(j-1>=0&&h[i][j]<=h[i][j-1]) dfs(h,i,j-1,m,n,vis);
        if(i+1<m&&h[i][j]<=h[i+1][j]) dfs(h,i+1,j,m,n,vis);
        if(i-1>=0&&h[i][j]<=h[i-1][j]) dfs(h,i-1,j,m,n,vis);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();
        vector<vector<int>>ans; vector<vector<bool>>visa(m,vector<bool>(n,false)); vector<vector<bool>>visp(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) dfs(h,i,0,m,n,visp);
        for(int i=0;i<n;i++) dfs(h,0,i,m,n,visp);
        for(int i=0;i<m;i++) dfs(h,i,n-1,m,n,visa);
        for(int i=0;i<n;i++) dfs(h,m-1,i,m,n,visa);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visa[i][j]&&visp[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
