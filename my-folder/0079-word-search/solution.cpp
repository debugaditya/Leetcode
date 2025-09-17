class Solution {
public:
    bool f(int i,int j,int idx,vector<vector<char>>& b, string w,vector<vector<bool>>&vis){
        if(idx==w.size()) return true;
        if(i==b.size()||i<0||j<0||j==b[0].size()) return false;
        if(vis[i][j]) return false; 
        if(w[idx]!=b[i][j]) return false;
        vis[i][j]=true;
        bool ans=false;
        ans|=f(i+1,j,idx+1,b,w,vis);
        if(!ans) ans|=f(i-1,j,idx+1,b,w,vis);
        if(!ans) ans|=f(i,j+1,idx+1,b,w,vis);
        if(!ans) ans|=f(i,j-1,idx+1,b,w,vis);
        vis[i][j]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& b, string w) {
        vector<vector<bool>>vis(b.size(),vector<bool>(b[0].size(),false));
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(f(i,j,0,b,w,vis)) return true;
            }
        }
        return false;
    }
};

