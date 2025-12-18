class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans=0;
        vector<int>v(101,0);
        for(auto it:nums){
            if(it>=k) ans+=v[it-k];
            if(it+k<101) ans+=v[it+k];
            v[it]++;
        }
        return ans;
    }
};
