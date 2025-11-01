class Solution {
public:
    bool check(int n,int mid,vector<int>& q){
        int ans=0;
        for(auto &it:q) ans+=ceil(1.0*it/mid);
        return ans<=n;
    }
    int minimizedMaximum(int n,vector<int>& q) {
        int l=1,r=*max_element(q.begin(),q.end());
        while(l<=r){
            int mid=(l+r)/2;
            if(check(n,mid,q)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
