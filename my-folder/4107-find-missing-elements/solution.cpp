class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end()); vector<int>v; int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            while(mini!=nums[i]) {v.push_back(mini); mini++;}
            mini++;
        }
        return v;
    }
};
