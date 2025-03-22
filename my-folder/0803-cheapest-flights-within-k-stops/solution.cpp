class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:f) graph[it[0]].push_back({it[1],it[2]});
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{src,0}});
        vector<vector<int>> ans(n, vector<int>(k + 2, INT_MAX));
        ans[src][0] = 0;
        while(!pq.empty()){
            int price=pq.top().first;
            int node=pq.top().second.first;
            int stops=pq.top().second.second;
            pq.pop();
            if(stops>k) continue;
            for(auto it:graph[node]){
                if(ans[it.first][stops+1]>price+it.second){
                    ans[it.first][stops+1]=price+it.second;
                    pq.push({price+it.second,{it.first,stops+1}});
                }
            }
        }
        int minCost = INT_MAX;
        for (int i = 0; i <= k + 1; i++) {
            minCost = min(minCost, ans[dst][i]);
        }

        return minCost == INT_MAX ? -1 : minCost;
    }
};
