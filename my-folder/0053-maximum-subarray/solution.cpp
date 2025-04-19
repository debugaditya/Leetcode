class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(auto it:nums){
            if(sum<0) sum=0;
            sum+=it;
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};
