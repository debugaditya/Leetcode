class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int l=1;
        int r=*max_element(c.begin(),c.end());
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            long long cnt=0;
            for(auto it:c) cnt+=it/mid;
            if(cnt>=k){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
