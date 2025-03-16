class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        vector<int>indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++) for(auto it:graph[i]) adj[it].push_back(i); 
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
        sort(topo.begin(),topo.end());
        return topo;
    }
};
