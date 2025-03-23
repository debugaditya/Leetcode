class Solution {
public:    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,int>>>graph(n);
        vector<int> ways(n,0);
        ways[0] = 1;
        int MOD = 1e9 + 7;
        for(auto it:roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>ans(n,LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        ans[0]=0;
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:graph[node]){
                if(ans[it.first]>dist+it.second){
                    ans[it.first]=dist+it.second;
                    ways[it.first] = ways[node];
                    pq.push({dist+it.second,it.first});
                }
                else if(ans[it.first]==dist+it.second) ways[it.first] = (ways[it.first] + ways[node]) % MOD;
            }
        }
        return ways[n - 1];
    }
};
