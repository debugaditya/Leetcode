class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int>z(nums.begin()+nums.size()-k,nums.end());
        nums.erase(nums.begin()+nums.size()-k,nums.end());
        nums.insert(nums.begin(),z.begin(),z.end());
        return;
    }
};
