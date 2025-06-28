class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt1=0,prev=0,ans=0;
        if(count(nums.begin(),nums.end(),0)==0) return nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0&&i-1>=0&&nums[i-1]==1&&i+1<nums.size()&&nums[i+1]==1){
                prev=cnt1;
                cnt1=0; 
            }
            else if(nums[i]==0) {cnt1=0; prev=0;}
            else if(nums[i]==1){
                cnt1++;
                ans=max(ans,cnt1+prev); 
            }
        }
        ans=max(ans,cnt1+prev);
        return ans;
    }
};
