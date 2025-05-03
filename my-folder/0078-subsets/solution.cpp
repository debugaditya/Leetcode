class Solution {
public:
    void f(int index,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        f(index+1,nums,temp,ans);
        temp.pop_back();
        f(index+1,nums,temp,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,nums,temp,ans);
        return ans;
    }
};
