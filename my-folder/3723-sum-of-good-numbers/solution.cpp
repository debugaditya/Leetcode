class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            bool d=true;
            if(i-k>=0&&nums[i-k]>=nums[i]) d=false;
            if(i+k<nums.size()&&nums[i+k]>=nums[i]) d=false;
            if(d) cnt+=nums[i];
        }
        return cnt;
    }
};
