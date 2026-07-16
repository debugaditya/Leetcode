class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0; int mx=nums[0];
        for(auto &it:nums){
            mx=max(mx,it);
            it=gcd(it,mx);
        }
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r) ans+=gcd(nums[l++],nums[r--]);
        return ans;
    }
};
