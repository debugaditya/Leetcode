class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        for(auto it:trust) adj[it[0]].push_back(it[1]);
        unordered_set<int>st;
        for(int i=1;i<adj.size();i++) if(adj[i].size()==0) st.insert(i);
        if(st.size()==0) return -1; vector<int>mp(n+1);
        for(auto it:adj) for(auto it1:it) mp[it1]++;
        for(auto it:st) if(mp[it]==n-1) return it;
        return -1; 
    }
};
