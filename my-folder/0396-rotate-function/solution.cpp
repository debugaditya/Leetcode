class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0),ans=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++) {ans+=nums[i]*i; maxi=ans;}
        for(int i=1;i<nums.size();i++){
            ans-=sum-nums[i-1]; ans+=(nums.size()-1)*nums[i-1];
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};
