class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long>freq,pair; long long ans=0;
        for(auto it:nums){
            if(it%2==0) ans=(ans+pair[it/2])%1000000007;
            pair[it]+=freq[2*it];
            freq[it]++;
        }
        return ans;
    }
};
