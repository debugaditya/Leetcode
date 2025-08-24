class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0,curr=0,rem=0,ans=0;
        for(auto it:nums){
            if(it==1) {cnt++; curr++;}
            else{
                if(rem==0) rem++;
                else {ans=max(cnt,ans); cnt=curr;}
                curr=0;
            }
        }
        ans=max(cnt,ans); 
        ans=min(ans,(int)nums.size()-1);
        return ans;
    }
};
