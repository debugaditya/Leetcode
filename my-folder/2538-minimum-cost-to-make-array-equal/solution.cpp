class Solution {
public:
    long long f(vector<int>& nums, vector<int>& cost, int mid){
        long long ans=0;
        for(int i=0;i<nums.size();i++) ans+=1LL*abs(mid-nums[i])*cost[i];
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=0,r=1000000; long long ans=LLONG_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            long long c1=f(nums,cost,mid);
            long long c2=f(nums,cost,mid+1);
            ans=min({ans,c1,c2});
            if(c1<c2) r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
