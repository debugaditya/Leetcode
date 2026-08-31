class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<vector<double>>v; priority_queue<int>pq; double ans=DBL_MAX,sum=0;
        for(int i=0;i<q.size();++i) v.push_back({(double)(w[i])/q[i],(double)q[i]});
        sort(v.begin(),v.end());
        for(auto it:v){
            sum+=it[1],pq.push(it[1]);
            if(pq.size()>k) sum-=pq.top(),pq.pop();
            if(pq.size()==k) ans=min(ans,1.0*it[0]*sum);
        }
        return ans;
    }
};
