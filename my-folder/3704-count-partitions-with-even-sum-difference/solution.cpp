class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0),sum1=0,cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            sum1+=nums[i];
            if((sum-sum1)%2==sum1%2) cnt++;
        }
        return cnt;
    }
};
