class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        long long maxi=-10,ans=1,cnt=0;  
        for(auto it:nums){if(it==0) continue; if(it<0) {maxi=max(maxi,1LL*it);} cnt++; ans*=it;}
        if(cnt==0) return 0;
        if(ans>0) return ans;
        if(cnt==1&&ans<0) return 0;
        return ans/maxi;
    }
};
