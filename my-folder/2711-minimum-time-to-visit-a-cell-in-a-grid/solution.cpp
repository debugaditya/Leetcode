class Solution {
public:
    int minimumTime(vector<vector<int>>& m) {
        if (m[0][1] > 1 && m[1][0] > 1) return -1;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0}); 
        vector<vector<int>>dist(m.size(),vector<int>(m[0].size(),INT_MAX)); dist[0][0]=0;
        while(!pq.empty()){
            auto [time,x,y]=pq.top(); pq.pop(); 
            if (time > dist[x][y]) continue;
            if(x-1>=0) {int nt = max(time+1, m[x-1][y] + ((m[x-1][y]-time)%2==0)); if(dist[x-1][y]>nt) {dist[x-1][y]=nt; pq.push({nt,x-1,y});} }
            if(y-1>=0) {int nt = max(time+1, m[x][y-1] + ((m[x][y-1]-time)%2==0)); if(dist[x][y-1]>nt) {dist[x][y-1]=nt; pq.push({nt,x,y-1});} }
            if(x+1<m.size()) {int nt = max(time+1, m[x+1][y] + ((m[x+1][y]-time)%2==0)); if(dist[x+1][y]>nt) {dist[x+1][y]=nt; pq.push({nt,x+1,y});} }
            if(y+1<m[0].size()) {int nt = max(time+1, m[x][y+1] + ((m[x][y+1]-time)%2==0)); if(dist[x][y+1]>nt) {dist[x][y+1]=nt; pq.push({nt,x,y+1});} }
        }
        return dist.back().back()==INT_MAX?-1:dist.back().back();
    }
};
