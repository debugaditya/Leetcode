class Solution {
public:
    void f(int i,vector<int>& nums,vector<int>&temp,set<vector<int>>&st){
        if(i==nums.size()){if(temp.size()>1) st.insert(temp); return;}
        f(i+1,nums,temp,st);
        if(temp.size()==0||nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            f(i+1,nums,temp,st);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st; vector<int>temp;
        f(0,nums,temp,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
