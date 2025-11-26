class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        vector<vector<pair<int,int>>>adj(fees.size());
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>minTime(fees.size(),INT_MAX);
        pq.push({fees[0],{0,0}});
        minTime[0]=0;
        while(!pq.empty()){
            int price=pq.top().first;
            int node=pq.top().second.first;
            int time=pq.top().second.second;
            pq.pop();
            if(node==fees.size()-1&&time<=maxTime) return price;
            for(auto it:adj[node]){
                int nxt=it.first;
                int t=it.second;
                int newTime=time+t;
                int newPrice=price+fees[nxt];
                if(newTime<=maxTime&&newTime<minTime[nxt]){
                    minTime[nxt]=newTime;
                    pq.push({newPrice,{nxt,newTime}});
                }
            }
        }
        return -1;
    }
};

