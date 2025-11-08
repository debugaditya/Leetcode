class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(auto it:nums) ans+=nums.back()-it;
        return ans;
    }
};
