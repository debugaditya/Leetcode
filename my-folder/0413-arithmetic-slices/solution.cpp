class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int diff=nums[1]-nums[0],cnt=2,ans=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==diff) cnt++;
            else{
                ans+=cnt*(cnt+1)/2;
                ans-=2*cnt-1;
                cnt=2; diff=nums[i]-nums[i-1];
            }
        }
        ans+=cnt*(cnt+1)/2; ans-=2*cnt-1;
        return ans;
    }
};
