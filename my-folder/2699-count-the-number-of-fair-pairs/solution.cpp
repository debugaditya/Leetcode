class Solution {
public:
    int lower_bound(int n,vector<int>& nums){
        int l=0;
        int r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>=n) r=mid;
            else l=mid+1;
        }
        return l;
    }
    int upper_bound(int n,vector<int>& nums){
        int l=0;
        int r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<=n) l=mid+1;    
            else r=mid;
        }
        return l;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j1=lower-nums[i];
            int j2=upper-nums[i];
            int lb = lower_bound(j1, nums);
            int ub = upper_bound(j2, nums);
            if (ub > i + 1) {
                ans += (ub - max(lb, i + 1));
            }
        }
        return ans;
    }
};
