class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans=0;
        for(auto &it:nums) sort(it.begin(),it.end());
        for(int i=0;i<nums[0].size();i++){
            int maxi=-1;
            for(auto &it:nums) maxi=max(maxi,it[i]);
            ans+=maxi;
        }
        return ans;
    }
};
