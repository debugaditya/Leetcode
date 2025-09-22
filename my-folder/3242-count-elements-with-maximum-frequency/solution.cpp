class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0,cnt=0; vector<int>mp(101,0);
        for(auto it:nums){
            mp[it]++;
            if(maxi<mp[it]) cnt=1;
            if(maxi==mp[it]) cnt++;
            maxi=max(maxi,mp[it]);
        }
        return cnt*maxi;
    }
};
