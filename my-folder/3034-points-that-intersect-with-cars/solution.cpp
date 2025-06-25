class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end()); int mini=0,maxi=-1,ans=0;
        for(auto it:nums){
            if(it[0]>maxi){
                ans+=maxi-mini+1;
                mini=it[0];
            }
            maxi=max(it[1],maxi);
        }
        ans+=maxi-mini+1;
        return ans;
    }
};
