class Solution {
public:
    vector<int>topo(vector<vector<int>>&adj){
        vector<int>ans(adj.size()),indegree(adj.size(),0); queue<int>q; int cnt=0;
        for(int i=1;i<adj.size();i++) for(int j:adj[i]) indegree[j]++;
        for(int i=1;i<adj.size();i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int i=q.front(); q.pop();
            ans[i]=cnt; cnt++; 
            for(auto it:adj[i]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        for(int i=1;i<adj.size();i++) if(indegree[i]>0) return {};
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<vector<int>>adj1(k+1),adj2(k+1),ans(k,vector<int>(k,0));
        for(auto it:r) adj1[it[0]].push_back(it[1]);
        for(auto it:c) adj2[it[0]].push_back(it[1]);
        vector<int>row=topo(adj1),col=topo(adj2);
        if(row.size()==0||col.size()==0) return {};
        for(int i=1;i<=k;i++) ans[row[i]][col[i]]=i;
        return ans;
    }
};
