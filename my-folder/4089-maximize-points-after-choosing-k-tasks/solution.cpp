class Solution {
public: 
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        priority_queue<pair<int,int>>pq; long long ans=0;
        for(int i=0;i<t1.size();i++){
            pq.push({t1[i]-t2[i],i});
        }
        while(k--){
            ans+=t1[pq.top().second];
            pq.pop();
        }
        while(!pq.empty()){
            ans+=max(t1[pq.top().second],t2[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
