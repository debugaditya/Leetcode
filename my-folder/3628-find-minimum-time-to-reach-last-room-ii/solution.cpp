class Solution {
public:
    int minTimeToReach(vector<vector<int>>& m) {
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;
        pq.push({0,0,0,0}); vector<vector<int>>dist(m.size(),vector<int>(m[0].size(),INT_MAX)); dist[0][0]=0;
        while(!pq.empty()){
            auto [time,x,y,mod]=pq.top(); pq.pop(); 
            if(x-1>=0&&dist[x-1][y]>max(time,m[x-1][y])+1+mod) {dist[x-1][y]=max(time,m[x-1][y])+1+mod; pq.push({max(time,m[x-1][y])+1+mod,x-1,y,1-mod});}
            if(y-1>=0&&dist[x][y-1]>max(time,m[x][y-1])+1+mod) {dist[x][y-1]=max(time,m[x][y-1])+1+mod; pq.push({max(time,m[x][y-1])+1+mod,x,y-1,1-mod});}
            if(x+1<m.size()&&dist[x+1][y]>max(time,m[x+1][y])+1+mod) {dist[x+1][y]=max(time,m[x+1][y])+1+mod; pq.push({max(time,m[x+1][y])+1+mod,x+1,y,1-mod});}
            if(y+1<m[0].size()&&dist[x][y+1]>max(time,m[x][y+1])+1+mod) {dist[x][y+1]=max(time,m[x][y+1])+1+mod; pq.push({max(time,m[x][y+1])+1+mod,x,y+1,1-mod});}
        }
        return dist.back().back();
    }
};
