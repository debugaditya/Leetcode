class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1=1;
        int ans2=1;
        int maxi=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                ans1++;
                maxi=max(maxi,ans2);
                ans2=1;
            }
            else if(nums[i-1]>nums[i]){
                ans2++;
                maxi=max(maxi,ans1);
                ans1=1;
            }
            else{
                maxi=max({maxi,ans1,ans2});
                ans1=1;
                ans2=1;
            }
        }
        maxi=max({maxi,ans1,ans2});
        return maxi;
    }
};
