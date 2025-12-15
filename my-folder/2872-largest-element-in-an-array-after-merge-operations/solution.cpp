class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans=0,sum=nums.back();
        for(int i=nums.size()-2;i>-1;i--){
            ans=max(ans,sum);
            if(nums[i]>sum) sum=0;
            sum+=nums[i];
        }
        ans=max(ans,sum);
        return ans;
    }
};
