class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto it:nums){
            if(mp[k-it]>0){
                ans++;
                mp[k-it]--;
            }
            else mp[it]++;
        }
        return ans;
    }
};
