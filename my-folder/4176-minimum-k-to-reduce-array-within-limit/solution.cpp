class Solution {
public:
    bool f(vector<int>& nums,int k){
        int ans=0;
        for(auto it:nums) ans+=ceil(1.0*it/k);
        return ans<=1LL*k*k;
    }
    int minimumK(vector<int>& nums) {
        int l=1,r=1000001;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(nums,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
