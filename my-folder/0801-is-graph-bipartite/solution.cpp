class Solution {
public:
    bool dfs(int node,int colour,vector<vector<int>>& g,vector<int>&nodes){
        nodes[node]=colour;
        for(auto it:g[node]){
            if(nodes[it]==-1&&!dfs(it,1-colour,g,nodes)) return false ;
            else if(nodes[it]==colour) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        vector<int>nodes(g.size(),-1);
        for(int i=0;i<g.size();i++) if(nodes[i]==-1&& !dfs(i,0,g,nodes)) return false;
        return true;
    }
};
