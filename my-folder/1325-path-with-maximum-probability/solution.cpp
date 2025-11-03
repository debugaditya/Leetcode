class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int s, int e) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],prob[i]});
            adj[edges[i][1]].push_back({edges[i][0],prob[i]});
        }
        queue<pair<int,double>>q; q.push({s,1}); vector<double>v(n); 
        while(!q.empty()){
            int node=q.front().first;
            double dist=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(v[it.first]<dist*it.second){
                    v[it.first]=dist*it.second;
                    q.push({it.first,dist*it.second});
                }
            }
        }
        return v[e];
    }
};
