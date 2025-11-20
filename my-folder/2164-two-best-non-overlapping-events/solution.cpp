class Solution {
public:
    vector<vector<int>>dp;
    int idx(vector<vector<int>>& events,int s){
        int l=0,r=events.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(events[mid][0]>s) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int f(int i,vector<vector<int>>& events,int k){
        if(i==events.size()||k<0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int pick=events[i][2]+f(idx(events,events[i][1]),events,k-1);
        int notpick=f(i+1,events,k);
        return dp[i][k]=max(pick,notpick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end()); dp.resize(events.size(),vector<int>(2,-1));
        return f(0,events,1);
    }
};
