class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,int>>pq; unordered_set<int>st; int ans=0;
        for(int i=0;i<y.size();i++) pq.push({y[i],i});
        while(!pq.empty()&&st.size()<3){
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(st.count(x[ind])) continue;
            st.insert(x[ind]); ans+=val;
        }
        if(st.size()<3) return -1;
        return ans;
    }
};
