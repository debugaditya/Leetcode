class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int>prev,dist; int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(dist.count(nums[i])) mini=min(mini,2*(dist[nums[i]]+i-prev[nums[i]]));
            if(prev.count(nums[i])) dist[nums[i]]=i-prev[nums[i]];
            prev[nums[i]]=i;
        }
        return mini==INT_MAX?-1:mini;
    }
};
