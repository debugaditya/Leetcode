class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto it:nums){
            mini=min(it,mini);
            maxi=max(it,maxi);
        }
        return gcd(maxi,mini);
    }
};
