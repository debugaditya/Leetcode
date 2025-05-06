class Solution {
public:
    void f(vector<int>& nums,vector<int>&temp,unordered_set<int>&st,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(st.count(i)) continue;
            temp.push_back(nums[i]);
            st.insert(i);
            f(nums,temp,st,ans);
            st.erase(i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_set<int>st;
        vector<int>temp;
        f(nums,temp,st,ans);
        return ans;
    }
};
