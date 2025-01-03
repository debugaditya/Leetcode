class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL),ans=0,sum1=0;
        for(int i=0;i<nums.size()-1;i++){sum1+=nums[i]; 
        if(sum1>=sum-sum1) ans++;}
        return ans;
    }
};
