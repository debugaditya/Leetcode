class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        priority_queue<int,vector<int>,greater<int>>pq; long long ans=0; int neg=INT_MAX,cnt=0; bool d=false;
        for(auto it:matrix) for(auto it1:it){ans+=abs(it1); if(it1==0) d=true; neg=min(neg,abs(it1)); if(it1<0) cnt++;}
        if(d) return ans;
        return ans-1LL*2*neg*(cnt%2);
    }
};
