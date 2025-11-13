class Solution {
public:
    bool check(vector<int>& prices,int k,int mid){
        int cnt=1,prev=prices[0];
        for(int i=1;i<prices.size();i++) if(prices[i]-prev>=mid){cnt++; prev=prices[i];}
        return cnt>=k;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int l=0,r=prices.back()-prices[0];
        while(l<=r){
            int mid=(l+r)/2;
            if(check(prices,k,mid)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};
