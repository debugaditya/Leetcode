class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>,vector<pair<pair<int,int>,int>>>mp; int ans=0; map<pair<int,int>,bool>vis;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{points[0][0],points[0][1]}});
        for(auto it:points){
            for(auto it1:points){
                if(it1==it) continue;
                mp[{it[0],it[1]}].push_back({{it1[0],it1[1]},abs(it[0]-it1[0])+abs(it[1]-it1[1])});
            }
        }
        while(!pq.empty()){
            int cost=pq.top().first;
            auto p=pq.top().second;
            pq.pop(); if(vis.count(p)) continue; ans+=cost; vis[p]=true;
            for(auto it:mp[p]) pq.push({it.second,it.first});
        }
        return ans;
    }
};
