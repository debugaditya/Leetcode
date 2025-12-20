class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;  int cnt=0;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==2) cnt++;
        }
        if(cnt==0) return 0;
        for(int i=0;i<nums.size();i++){
            int it=nums[i];
            mp[it]--;
            if(mp[it]==1) cnt--;
            if(cnt==0){
                return ceil(1.0*(i+1)/3);
            }
        }
        return -1;
    }
};
