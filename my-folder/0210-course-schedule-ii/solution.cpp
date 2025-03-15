class Solution {
public:
    vector<int> findOrder(int c, vector<vector<int>>& p) {
        vector<vector<int>>adj(c);
        for(auto it:p) adj[it[0]].push_back(it[1]);
        vector<int>indegree(adj.size(),0);
        for(auto it:adj) for(auto it1:it) indegree[it1]++;
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            topo.push_back(q.front());
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int>empty={};
        reverse(topo.begin(), topo.end());
        return topo.size()==adj.size()?topo:empty;
    }
};
