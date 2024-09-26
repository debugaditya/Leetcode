class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int>b;
    for (int i = 0; i < nums.size(); i++) {
        
        if (mp.find(target - nums[i]) != mp.end()) {
            b.push_back(i);
            b.push_back(mp[target - nums[i]]);
            
           
        } 
        mp[nums[i]]=i;
        
        
        
    }
    return b;
        
        
    }
};
