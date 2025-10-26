class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        for(auto &it:nums) it*=it;
        sort(nums.begin(),nums.end());
        int odd=nums.size()/2,even=nums.size()-odd;
        int i=nums.size()-1;
        while(even--) ans+=nums[i--];
        while(odd--) ans-=nums[i--];
        return ans;
    }
};
