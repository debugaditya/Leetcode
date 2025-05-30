class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>mp(k,0); int ans=0,sum=0;
        mp[0]=1;
        for(auto it:nums){
            sum+=it;
            ans+=mp[((sum % k) + k) % k];
            mp[((sum % k) + k) % k]++;
        }
        return ans;
    }
};
