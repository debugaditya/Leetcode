class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini_sum=0;
        int maxi_sum=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mini_sum=min(sum,mini_sum);
            maxi_sum=max(sum,maxi_sum);
            maxi=max(maxi,abs(sum-mini_sum));
            maxi=max(maxi,abs(sum-maxi_sum));
        }
        return maxi;
    }
};
