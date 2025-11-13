class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>temp=nums;
        for(auto it:temp) nums.push_back(it);
        return nums;
    }
};
