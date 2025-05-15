class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]) v.push_back(nums[0]);
        if(nums[nums.size()-2]!=nums[nums.size()-1]) v.push_back(nums[nums.size()-1]);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]) v.push_back(nums[i]);
            if(v.size()==2) break;
        }
        return v;
    }
};
