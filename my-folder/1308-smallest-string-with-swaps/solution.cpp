class Solution {
public:
    void dfs(string &s,vector<vector<int>>&adj,int i,vector<bool>&vis,string &temp,vector<int>&idx){
        if(vis[i]) return;
        temp+=s[i]; idx.push_back(i); vis[i]=true;
        for(auto it:adj[i]) dfs(s,adj,it,vis,temp,idx);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>>adj(s.size()); vector<bool>vis(s.size(),false); vector<char>ans(s.size());
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<s.size();i++) {
            if(!vis[i]) {
                string temp=""; vector<int>idx; 
                dfs(s,adj,i,vis,temp,idx);
                sort(temp.begin(),temp.end()); sort(idx.begin(),idx.end());
                for(int i=0;i<idx.size();i++) ans[idx[i]]=temp[i];
            }
        }
        string t=""; for(auto it:ans) t+=it;
        return t;
    }
};
