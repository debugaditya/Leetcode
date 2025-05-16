class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r, int c, int color) {
        map<pair<int,int>,int>vis;
        vector<pair<int,int>>comp;
        queue<pair<int,int>>q;
        vector<pair<int,int>>ans;
        q.push({r,c});
        while(!q.empty()){
            int newr=q.front().first;
            int newc=q.front().second;
            q.pop();
            if(newr>=g.size()||newc>=g[0].size()||newr<0||newc<0||g[newr][newc]!=g[r][c]||vis[{newr,newc}]==1) continue;
            comp.push_back({newr,newc});
            q.push({newr+1,newc});
            q.push({newr-1,newc});
            q.push({newr,newc+1});
            q.push({newr,newc-1});
            vis[{newr,newc}]=1;
        }
        for(auto it:comp){
            int row=it.first;
            int col=it.second;
            if(row==g.size()-1||col==g[0].size()-1||row==0||col==0) ans.push_back(it);
            else if(g[row][col]!=g[row+1][col]||g[row][col]!=g[row][col+1]||g[row][col]!=g[row][col-1]||g[row][col]!=g[row-1][col]) ans.push_back(it);
        }
        for(auto it:ans) g[it.first][it.second]=color;
        return g;
    }
};
