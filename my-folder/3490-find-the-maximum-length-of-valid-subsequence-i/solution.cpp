class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0,cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) odd++;
            else even++;
            if(i>0&&nums[i]%2!=nums[i-1]%2) cnt++;
        }
        return max({odd,even,cnt});
    }
};
