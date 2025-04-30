class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        int r=0;
        long long sum=nums[0];
        long long ans=0;
        while(r<nums.size()){
            if(1LL*sum*(r-l+1)<k){
                ans+=(r-l+1);
                r++;
                if(r<nums.size()) sum+=nums[r];
            }
            else{
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};
