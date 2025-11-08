class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int>mp(m+n,0); int l=1,r=m*n;
        while(l<=r){
            int mid=(l+r)/2,ans=0;
            for(int i=1;i<=m;i++) ans+=min(n,mid/i);
            if(ans>=k)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
