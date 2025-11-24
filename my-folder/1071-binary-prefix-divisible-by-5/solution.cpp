class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=0; vector<bool>ans;
        for(auto it:nums){n*=2; n+=it; if(n%5==0) ans.push_back(true); else ans.push_back(false); n%=5;}
        return ans;
    }
};
