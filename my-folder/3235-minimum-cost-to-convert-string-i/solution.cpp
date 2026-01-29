class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<vector<int>>grid=vector<vector<int>>(26,vector<int>(26,-1));
    int dist(vector<vector<vector<int>>>&adj,int start,int des){
        if(grid[start][des]!=-1) return grid[start][des];
        vector<int>v(26,INT_MAX);
        pq.push({0,start}); v[start]=0;
        while(!pq.empty()){
            auto [d,ch]=pq.top(); pq.pop();
            if(d>v[ch]) continue;
            for(auto it:adj[ch]){
                if(d+it[1]<v[it[0]]){
                    v[it[0]]=d+it[1];
                    pq.push({d+it[1],it[0]});
                }
            }
        }
        for(int i=0;i<26;i++) grid[start][i]=v[i];
        return v[des]==INT_MAX?-1:v[des];
    }
    long long minimumCost(string src, string tar, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<vector<int>>>adj(26); long long ans=0;
        for(int i=0;i<o.size();i++) adj[o[i]-'a'].push_back({c[i]-'a',cost[i]});
        for(int i=0;i<26;i++) dist(adj, i, 0); 
        for(int i=0;i<src.size();i++){
            int d=grid[src[i]-'a'][tar[i]-'a'];
            if(d==INT_MAX||d<0) return -1;
            ans+=d;
        }
        return ans;
    }
};


