class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double,vector<double>,greater<double>>pq; int ans=0,time=0;
        for(int i=0;i<dist.size();i++) pq.push(1.0*dist[i]/speed[i]);
        while(!pq.empty()){
            if(pq.top()>time) ans++;
            else break;
            pq.pop();
            time++;
        }
        return ans;
    }
};
