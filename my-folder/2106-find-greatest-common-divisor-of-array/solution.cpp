class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:nums){
            mini=min(it,mini);
            maxi=max(it,maxi);
        }
        while(maxi%mini!=0){
            int temp=maxi;
            maxi=mini;
            mini=temp%mini;
        }
        return mini;
    }
};
