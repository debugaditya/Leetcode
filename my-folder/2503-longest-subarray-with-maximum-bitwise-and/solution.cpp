class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0,cnt=0,ans=0;
        for(auto it:nums){
            if(it>maxi){maxi=it; cnt=1; ans=1;}
            else if(it==maxi) cnt++;
            else {ans=max(cnt,ans); cnt=0;}
        }
        ans=max(cnt,ans);
        return ans;
    }
};
